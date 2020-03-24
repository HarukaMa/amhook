#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

int32_t AimePayCheckInPinCodeLength_get() {
	log("\n");
	return 4;
}

void* AimePay_getActivatedLocationInfo() {
	log("\n");
	return 0x8;
}

void* AimePay_getCurrentLocationInfo() {
	log("\n");
	return 0x9;
}

void* AimePay_getDealResult(int32_t index) {
	log("%d\n", index);
	return 0xA;
}

int32_t AimePay_getDealResultCount() {
	log("\n");
	return 0;
}

void* AimePay_getDealSummary(int32_t index) {
	log("%d\n", index);
	return 0xB;
}

int32_t AimePay_getDealSummaryCount() {
	log("\n");
	return 0;
}

void* AimePay_getOperation() {
	log("\n");
	return 0xC;
}

bool AimePay_isActivated() {
	log("\n");
	return 0;
}

bool AimePay_isAvailable() {
	log("\n");
	return 0;
}

uint32_t MaxAimePayAmountCount_get() {
	log("\n");
	return 99999;
}

int32_t MaxAimePayErrorCodeLength_get() {
	log("\n");
	return 18;
}

int32_t MaxAimePayItemIdLength_get() {
	log("\n");
	return 13;
}