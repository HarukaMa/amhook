#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t CreditConfig_MaxCoinChuteCount_get() {
	log("\n");
	return 2;
}

int32_t CreditConfig_MaxGameCostCount_get() {
	log("\n");
	return 8;
}

uint32_t CreditConfig_bonusAdder_get(void *config) {
	log("%p\n", config);
	return 0;
}

uint32_t CreditConfig_coinAmount_get(void* config) {
	log("%p\n", config);
	return 0;
}

bool CreditConfig_coinChuteCommon_get(void* config) {
	log("%p\n", config);
	return false;
}

uint32_t CreditConfig_coinMultipliers_get(void *config, int32_t coinChuteIndex) {
	log("%p %d\n", config, coinChuteIndex);
	return 0;
}

uint32_t CreditConfig_coinToCredit_get(void* config) {
	log("%p\n", config);
	return 0;
}

bool CreditConfig_freePlay_get(void* config) {
	log("%p\n", config);
	return false;
}

uint32_t CreditConfig_gameCosts_get(void* config, int32_t gameCostIndex) {
	log("%p %d\n", config, gameCostIndex);
	return 0;
}

bool CreditConfig_serviceCommon_get(void* config) {
	log("%p\n", config);
	return false;
}