#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum NetworkTestItem {
	IpAddress,
	Gateway,
	LanDns,
	Hops,
	LineType,
	AllnetAuth,
	Aime,
	EMoney,
	AimePay
};

enum TestResult {
	ResultNone,
	NA,
	Good,
	Bad
};

enum NetworkTestState {
	StateNone,
	Busy,
	Done
};

enum NetworkTestItem NetworkTestInfo_getAvailableItem(void *info, int32_t index) {
	log("%p %d\n", info, index);
	if (index >= 4) {
		return index + 1;
	}
	return index;
}

int32_t NetworkTestInfo_getAvailableItemCount(void* info) {
	log("%p\n", info);
	return 8;
}

wchar_t* NetworkTestInfo_getBusyStatusText(bool blink) {
	log("%d\n", blink);
	return L"CHECK";
}

void* NetworkTestInfo_getErrorInfo(void* info) {
	log("%p\n", info);
	return 0x3E;
}

int32_t NetworkTestInfo_getHops(void* info) {
	log("%p\n", info);
	return 16;
}

enum TestResult NetworkTestInfo_getResult(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return Good;
}

enum NetworkTestState NetworkTestInfo_getState(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return Done;
}

wchar_t* NetworkTestInfo_getStatusText(void* info, enum NetworkTestItem item, bool blinkBusy) {
	log("%p %d %d\n", info, item, blinkBusy);
	return L"GOOD";
}

bool NetworkTestInfo_isAvailableItem(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return true;
}

bool NetworkTestInfo_isBusy(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return false;
}

bool NetworkTestInfo_isCompleted(void* info) {
	log("%p\n", info);
	return true;
}

bool NetworkTestInfo_isDone(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return true;
}

bool NetworkTestInfo_isRunning(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return false;
}
