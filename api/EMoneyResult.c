#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum EMoneyResultStatus {
	Fail,
	Success,
	Unconfirm,
	Incomplete
};

int32_t EMoneyResult_getAmount(void* report) {
	log("%p\n", report);
	return 0;
}

int32_t EMoneyResult_getBalanceAfter(void* report) {
	log("%p\n", report);
	return 0;
}

int32_t EMoneyResult_getBalanceBefore(void* report) {
	log("%p\n", report);
	return 0;
}

void* EMoneyResult_getBrand(void* report) {
	log("%p\n", report);
	return 0x2700 + (int)report % 0x100;
}

wchar_t* EMoneyResult_getCardNumber(void* report) {
	log("%p\n", report);
	return 0;
}

wchar_t* EMoneyResult_getDealNumber(void* report) {
	log("%p\n", report);
	return 0;
}

enum EMoneyResultStatus EMoneyResult_getStatus(void* report) {
	log("%p\n", report);
	return Success;
}

uint64_t EMoneyResult_getTime(void* report) {
	log("%p\n", report);
	return 0;
}

bool EMoneyResult_valid(void* report) {
	log("%p\n", report);
	return true;
}