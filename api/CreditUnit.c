#include <stdbool.h>
#include <stdint.h>

#include "log.h"

uint32_t CreditUnit_getAddableCoin(void *unit) {
	log("%p\n", unit);
	return 1;
}

uint32_t CreditUnit_getCoinToCredit(void* unit) {
	log("%p\n", unit);
	return 1;
}

uint32_t CreditUnit_getCredit(void* unit) {
	log("%p\n", unit);
	return 1;
}

uint32_t CreditUnit_getGameCost(void *unit, int32_t gameCostIndex) {
	log("%p %d\n", unit, gameCostIndex);
	return 0;
}

uint32_t CreditUnit_getRemain(void* unit) {
	log("%p\n", unit);
	return 0;
}

bool CreditUnit_isFreePlay(void* unit) {
	log("%p\n", unit);
	return false;
}

bool CreditUnit_isGameCostEnough(void *unit, int32_t gameCostIndex, int32_t count) {
	log("%p %d %d\n", unit, gameCostIndex, count);
	return true;
}

bool CreditUnit_isZero(void* unit) {
	log("%p\n", unit);
	return false;
}

bool CreditUnit_payGameCost(void* unit, int32_t gameCostIndex, int32_t count) {
	log("%p %d %d\n", unit, gameCostIndex, count);
	return false;
}

wchar_t* CreditUnit_toString(void* unit) {
	log("%p\n", unit);
	return 0;
}
