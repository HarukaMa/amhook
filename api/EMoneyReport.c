#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum EMoneyResultStatus {
	Fail,
	Success,
	Unconfirm,
	Incomplete
};

int32_t EMoneyReport_getAlarmAmount(void *report) {
	log("%p\n", report);
	return 0;
}

int32_t EMoneyReport_getAlarmCount(void* report) {
	log("%p\n", report);
	return 0;
}

int32_t EMoneyReport_getAmount(void* report) {
	log("%p\n", report);
	return 0;
}

int32_t EMoneyReport_getCount(void* report) {
	log("%p\n", report);
	return 0;
}

uint64_t EMoneyReport_getTime(void* report) {
	log("%p\n", report);
	return 0;
}

bool EMoneyReport_isSucceeded(void* report) {
	log("%p\n", report);
	return 0;
}

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
	return 0x27;
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
	return Fail;
}

uint64_t EMoneyResult_getTime(void* report) {
	log("%p\n", report);
	return 0;
}

bool EMoneyResult_valid(void* report) {
	log("%p\n", report);
	return false;
}