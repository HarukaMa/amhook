#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

enum AimeCommand {
	ScanOffline,
	Scan
};

enum AimeConfirm {
	None,
	FeliCaDB,
	AimeDB
};

enum AimeLedStatus {
	LedNone,
	Scanning,
	Success,
	Warning,
	Error
};

extern enum AimeErrorCategory aime_error_category;
extern enum AimeErrorId aime_error_id;

bool aime_unit_is_canceled = false;
bool aime_unit_has_card = false;
bool aime_unit_is_busy = false;
bool aime_unit_has_error = false;
bool aime_unit_has_confirm = false;
bool aime_unit_has_result = false;

char access_code[21] = { 0 };
uint32_t aime_id = 0;

DWORD WINAPI aime_unit_run(void *_) {
	aime_unit_is_canceled = false;
	aime_unit_has_error = false;
	aime_unit_has_confirm = false;
	aime_unit_has_result = false;
	aime_unit_is_busy = true;
	while (!aime_unit_has_card) {
		if (aime_unit_is_canceled) {
			aime_unit_is_canceled = false;
			aime_unit_is_busy = false;
			return 0;
		}
		Sleep(50);
	}
	FILE* f = fopen("card.txt", "r");
	if (f) {
		size_t size = fread(access_code, 1, 20, f);
		fclose(f);
		if (size < 20) {
			aime_error_id = 14;
			aime_error_category = 3;
RETURN:
			log("Error ID %d\n", aime_error_id);
			aime_unit_has_error = true;
			aime_unit_has_result = true;
			aime_unit_is_busy = false;
			memset(access_code, 0, 21);
			return 0;
		}
		for (int i = 0; i < 20; i ++) {
			if (!isdigit(access_code[i])) {
				aime_error_id = 14;
				aime_error_category = 3;
				goto RETURN;
			}
		}
		HINTERNET session = WinHttpOpen(L"AMDaemon", WINHTTP_ACCESS_TYPE_NO_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
		DWORD error;
		if (!session) {
			error = GetLastError();
NET_ERROR:
			aime_error_id = 10;
			aime_error_category = 2;
			wchar_t* buffer;
			FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, error, 0, &buffer, 0, NULL);
			log("%ls\n", buffer);
			goto RETURN;
		}
		HINTERNET conn = WinHttpConnect(session, L"raw.mrx.im", 10500, 0);
		if (!conn) {
			error = GetLastError();
			WinHttpCloseHandle(session);
			goto NET_ERROR;
		}
		wchar_t buffer[50] = { 0 };
		wsprintf(buffer, L"/get_aime_id?access_code=%hs", access_code);
		HINTERNET req = WinHttpOpenRequest(conn, L"GET", buffer, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
		if (!req) {
			error = GetLastError();
			WinHttpCloseHandle(conn);
			WinHttpCloseHandle(session);
			goto NET_ERROR;
		}
		bool res = WinHttpSendRequest(req, WINHTTP_NO_ADDITIONAL_HEADERS, 0, NULL, 0, 0, 0);
		if (!res) {
			error = GetLastError();
NET_CLOSE:
			WinHttpCloseHandle(req);
			WinHttpCloseHandle(conn);
			WinHttpCloseHandle(session);
			goto NET_ERROR;
		}
		res = WinHttpReceiveResponse(req, NULL);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		unsigned int status_code;
		unsigned long status_code_size = 4;
		res = WinHttpQueryHeaders(req, WINHTTP_QUERY_FLAG_NUMBER | WINHTTP_QUERY_STATUS_CODE, WINHTTP_HEADER_NAME_BY_INDEX, &status_code, &status_code_size, WINHTTP_NO_HEADER_INDEX);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		if (status_code != 200) {
			aime_error_id = 15;
			aime_error_category = 3;
			WinHttpCloseHandle(req);
			WinHttpCloseHandle(conn);
			WinHttpCloseHandle(session);
			goto RETURN;
		}
		unsigned long available;
		res = WinHttpQueryDataAvailable(req, &available);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		char id_buffer[11] = { 0 };
		unsigned long read;
		res = WinHttpReadData(req, id_buffer, available, &read);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		aime_id = strtoul(id_buffer, NULL, 10);
		WinHttpCloseHandle(req);
		
		wsprintf(buffer, L"/aime_id_exist?aime_id=%u", aime_id);
		req = WinHttpOpenRequest(conn, L"GET", buffer, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
		if (!req) {
			error = GetLastError();
			WinHttpCloseHandle(conn);
			WinHttpCloseHandle(session);
			goto NET_ERROR;
		}
		res = WinHttpSendRequest(req, WINHTTP_NO_ADDITIONAL_HEADERS, 0, NULL, 0, 0, 0);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		res = WinHttpReceiveResponse(req, NULL);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		res = WinHttpQueryHeaders(req, WINHTTP_QUERY_FLAG_NUMBER | WINHTTP_QUERY_STATUS_CODE, WINHTTP_HEADER_NAME_BY_INDEX, &status_code, &status_code_size, WINHTTP_NO_HEADER_INDEX);
		if (!res) {
			error = GetLastError();
			goto NET_CLOSE;
		}
		if (status_code == 200) {
			aime_unit_is_busy = false;
			aime_unit_has_result = true;
		} else if (status_code == 404) {
			aime_unit_has_confirm = true;
			aime_unit_has_result = true;
		}
	} else {
		aime_error_id = 14;
		aime_error_category = 3;
		goto RETURN;
	}
	
	return 0;
}

bool AimeUnit_acceptConfirm(void *unit) {
	log("%p\n", unit);
	aime_unit_is_busy = false;
	return true;
}

bool AimeUnit_canStart(void* unit) {
	log("%p\n", unit);
	return true;
}

bool AimeUnit_cancel(void* unit) {
	log("%p\n", unit);
	aime_unit_is_canceled = true;
	aime_unit_is_busy = false;
	return true;
}

enum AimeCommand AimeUnit_getBusyCommand(void* unit) {
	log("%p\n", unit);
	return Scan;
}

enum AimeConfirm AimeUnit_getConfirm(void* unit) {
	log("%p\n", unit);
	return AimeDB;
}

void* AimeUnit_getErrorInfo(void* unit) {
	log("%p\n", unit);
	return 0xE;
}

enum AimeLedStatus AimeUnit_getLedStatus(void* unit) {
	log("%p\n", unit);
	return Success;
}

void* AimeUnit_getResult(void* unit) {
	log("%p\n", unit);
	return 0xF;
}

bool AimeUnit_hasConfirm(void* unit) {
	log("%p\n", unit);
	return aime_unit_has_confirm;
}

bool AimeUnit_hasError(void* unit) {
	log("%p\n", unit);
	return aime_unit_has_error;
}

bool AimeUnit_hasResult(void* unit) {
	log("%p\n", unit);
	return aime_unit_has_result;
}

bool AimeUnit_isBusy(void* unit) {
	log("%p\n", unit);
	return aime_unit_is_busy;
}

bool AimeUnit_setLed(void *unit, bool onR, bool onG, bool onB) {
	log("%p %d %d %d\n", unit, onR, onG, onB);
	return true;
}

bool AimeUnit_setLedStatus(void *unit, enum AimeLedStatus status) {
	log("%p %d\n", unit, status);
	return true;
}

bool AimeUnit_start(void *unit, enum AimeCommand command) {
	log("%p %d\n", unit, command);
	CreateThread(NULL, 0, &aime_unit_run, NULL, 0, 0);
	return true;
}
