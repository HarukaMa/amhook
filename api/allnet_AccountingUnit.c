#include <stdbool.h>
#include <stdint.h>

#include "log.h"

bool allnet_AccountingUnit_accountItem(void *unit, int32_t kindCode, int32_t statusCode,  int32_t itemCount) {
	log("%p %d %d %d\n", unit, kindCode, statusCode, itemCount);
	return false;
}

uint32_t allnet_AccountingUnit_beginPlay(void *unit, int32_t kindCode, int32_t statusCode) {
	log("%p %d %d\n", unit, kindCode, statusCode);
	return 0;
}

bool allnet_AccountingUnit_canBeginPlay(void *unit) {
	log("%p\n", unit);
	return false;
}

uint32_t allnet_AccountingUnit_continuePlay(void* unit, uint32_t prevHandle, int32_t prevKindCode, int32_t prevStatusCode, int32_t prevItemCount, int32_t nextKindCode, int32_t nextStatusCode) {
	log("%p %d %d %d %d %d %d\n", unit, prevHandle, prevKindCode, prevStatusCode, prevItemCount, nextKindCode, nextStatusCode);
	return 0;
}

bool allnet_AccountingUnit_endPlay(void* unit, uint32_t handle, uint32_t kindCode, int32_t statusCode, int32_t itemCount) {
	log("%p %d %d %d\n", unit, kindCode, statusCode, itemCount);
	return false;
}

int32_t allnet_AccountingUnit_getItemCountLimit() {
	log("\n");
	return 654;
}

int32_t allnet_AccountingUnit_getKindCodeLimit() {
	log("\n");
	return 654;
}

int32_t allnet_AccountingUnit_getMaxGeneralIdLength() {
	log("\n");
	return 654;
}

int32_t allnet_AccountingUnit_getQuantityLimit() {
	log("\n");
	return 654;
}

int32_t allnet_AccountingUnit_getStatusCodeLimit() {
	log("\n");
	return 654;
}

bool allnet_AccountingUnit_putGeneralId(void *unit, int32_t kindCode, wchar_t *generalId) {
	log("%p %d %ls\n", unit, kindCode, generalId);
	return false;
}

bool allnet_AccountingUnit_putQuantity(void* unit, int32_t kindCode, int32_t quantity) {
	log("%p %d %ls\n", unit, kindCode, quantity);
	return false;
}
