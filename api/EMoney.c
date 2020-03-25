#include <stdbool.h>
#include <stdint.h>

#include "log.h"

void* EMoney_getAvailableBrand(int32_t index) {
	log("%d\n", index);
	return 0x2200 + index;
}

int EMoney_getAvailableBrandCount() {
	log("\n");
	return 5;
}

void* EMoney_getDealResult(int32_t index) {
	log("%d\n", index);
	return 0x2300 + index;
}

int32_t EMoney_getDealResultCount() {
	log("\n");
	return 0;
}

void* EMoney_getOperation() {
	log("\n");
	return 0x24;
}

void* EMoney_getReport(int32_t index) {
	log("%d\n", index);
	return 0x2500 + index;
}

int32_t EMoney_getReportCount() {
	log("\n");
	return 0;
}

wchar_t* EMoney_getTerminalId() {
	log("\n");
	return L"EMONEY_TERMINAL_00";
}

wchar_t* EMoney_getTerminalSerial() {
	log("\n");
	return L"EMONEY_SERIAL_00";
}

bool EMoney_isAuthCompleted() {
	log("\n");
	return true;
}

bool EMoney_isAvailable() {
	log("\n");
	return true;
}

bool EMoney_isBrandAvailable(enum EMoneyBrandId brandId) {
	log("%d\n", brandId);
	return true;
}

bool EMoney_isReporting() {
	log("\n");
	return false;
}

bool EMoney_isServiceAlive() {
	log("\n");
	return true;
}

void EMoney_resetSoundHook() {
	log("\n");
}

void EMoney_setSoundHook(void (*hook)(intptr_t id, intptr_t filepath)) {
	log("\%p\n", hook);
}

int32_t MaxEMoneyBrandNameLength_get() {
	log("\n");
	return 15;
}

int32_t MaxEMoneyCardNumberLength_get() {
	log("\n");
	return 20;
}

int32_t MaxEMoneyDealNumberLength_get() {
	log("\n");
	return 20;
}

int32_t MaxEMoneyDealResultCount_get() {
	log("\n");
	return 20;
}

int32_t MaxEMoneyReportCount_get() {
	log("\n");
	return 20;
}

int32_t MaxEMoneyTerminalIdLength_get() {
	log("\n");
	return 30;
}

int32_t MaxEMoneyTerminalSerialLength_get() {
	log("\n");
	return 20;
}