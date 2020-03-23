#include <stdint.h>

#include "log.h"

int32_t CreditBookkeeping_CoinChuteCount_get() {
	log("\n");
	return 4;
}

uint32_t CreditBookkeeping_coinCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t CreditBookkeeping_coins_get(void *bookkeeping, int32_t coinChuteIndex) {
	log("%p %d\n", bookkeeping, coinChuteIndex);
	return 0;
}

uint32_t CreditBookkeeping_eMoneyCoin_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t CreditBookkeeping_eMoneyCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t CreditBookkeeping_serviceCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t CreditBookkeeping_totalCoin_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t CreditBookkeeping_totalCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}
