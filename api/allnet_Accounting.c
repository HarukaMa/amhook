#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum AccountingMode {
	None,
	A,
	B1,
	B2
};

enum AccountingPlayCountMonth {
	Current,
	Last,
	BeforeLast
};

uint64_t allnet_Accounting_getBackgroundReportTime() {
	log("\n");
	return 0;
}

enum AccountingMode allnet_Accounting_getMode() {
	log("\n");
	return None;
}

void* allnet_Accounting_getPlayCountItem(enum AccountingPlayCountMonth month) {
	log("%d\n", month);
	return 0x10;
}

void* allnet_Accounting_getPlayer(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return 0x11;
}

int32_t allnet_Accounting_getPlayerCount() {
	log("\n");
	return 1;
}

uint64_t allnet_Accounting_getReportTime() {
	log("\n");
	return 0;
}

int64_t allnet_Accounting_getSpanUntilReport() {
	log("\n");
	return 0;
}

bool allnet_Accounting_isAvailable() {
	log("\n");
	return true;
}

bool allnet_Accounting_isLogFull() {
	log("\n");
	return false;
}

bool allnet_Accounting_isNearFullEnabled() {
	log("\n");
	return false;
}

bool allnet_Accounting_isPlayable() {
	log("\n");
	return false;
}

bool allnet_Accounting_isReporting() {
	log("\n");
	return false;
}

bool allnet_Accounting_setNearFullEnabled(bool enabled) {
	log("%d\n", enabled);
	return false;
}
