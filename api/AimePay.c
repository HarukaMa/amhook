#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t AimePayCheckInPinCodeLength_get() {
	log("\n");
	return 4;
}

void* AimePay_getActivatedLocationInfo() {
	log("\n");
	return 0;
}

void* AimePay_getCurrentLocationInfo() {
	log("\n");
	return 0;
}

void* AimePay_getDealResult(int32_t index) {
	log("%d\n", index);
	return 0;
}

int32_t AimePay_getDealResultCount() {
	log("\n");
	return 0;
}

void* AimePay_getDealSummary(int32_t index) {
	log("%d\n", index);
	return 0;
}

int32_t AimePay_getDealSummaryCount() {
	log("\n");
	return 0;
}

void* AimePay_getOperation() {
	log("\n");
	return 0;
}

bool AimePay_isActivated() {
	log("\n");
	return 0;
}

bool AimePay_isAvailable() {
	log("\n");
	return 0;
}