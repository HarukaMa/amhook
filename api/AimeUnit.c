#include <stdbool.h>
#include <stdio.h>

#include "log.h"

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

bool AimeUnit_acceptConfirm(void *unit) {
	log("%p\n", unit);
	return false;
}

bool AimeUnit_canStart(void* unit) {
	log("%p\n", unit);
	return false;
}

bool AimeUnit_cancel(void* unit) {
	log("%p\n", unit);
	return false;
}

enum AimeCommand AimeUnit_getBusyCommand(void* unit) {
	log("%p\n", unit);
	return Scan;
}

enum AimeConfirm AimeUnit_getConfirm(void* unit) {
	log("%p\n", unit);
	return None;
}

void* AimeUnit_getErrorInfo(void* unit) {
	log("%p\n", unit);
	return 0;
}

enum AimeLedStatus AimeUnit_getLedStatus(void* unit) {
	log("%p\n", unit);
	return Error;
}

void* AimeUnit_getResult(void* unit) {
	log("%p\n", unit);
	return 0;
}

bool AimeUnit_hasConfirm(void* unit) {
	log("%p\n", unit);
	return false;
}

bool AimeUnit_hasError(void* unit) {
	log("%p\n", unit);
	return false;
}

bool AimeUnit_hasResult(void* unit) {
	log("%p\n", unit);
	return false;
}

bool AimeUnit_isBusy(void* unit) {
	log("%p\n", unit);
	return false;
}

bool AimeUnit_setLed(void *unit, bool onR, bool onG, bool onB) {
	log("%p %d %d %d\n", unit, onR, onG, onB);
	return false;
}

bool AimeUnit_setLedStatus(void *unit, enum AimeLedStatus status) {
	log("%p %d\n", unit, status);
	return false;
}

bool AimeUnit_start(void *unit, enum AimeCommand command) {
	log("%p %d\n", unit, command);
	return false;
}
