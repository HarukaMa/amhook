#include <stdint.h>

#include "log.h"

struct CreditBookkeeping {
	int coin_chute_1_coin;
	int emoney_coin;
	int coin_credit;
	int emoney_credit;
	int service_credit;
	int total_coin;
};

struct CreditBookkeeping bookkeeping_data;

void load_bookkeeping_data() {
	FILE* f = fopen("bookkeeping.dat", "rb");
	if (f) {
		fread(&bookkeeping_data, sizeof(struct CreditBookkeeping), 1, f);
		fclose(f);
	}
}

void save_bookkeeping_data() {
	FILE* f = fopen("bookkeeping.dat", "wb");
	if (f) {
		fwrite(&bookkeeping_data, sizeof(struct CreditBookkeeping), 1, f);
		fclose(f);
	}
}

int32_t CreditBookkeeping_CoinChuteCount_get() {
	log("\n");
	return 4;
}

uint32_t CreditBookkeeping_coinCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return bookkeeping_data.coin_credit;
}

uint32_t CreditBookkeeping_coins_get(void *bookkeeping, int32_t coinChuteIndex) {
	log("%p %d\n", bookkeeping, coinChuteIndex);
	if (coinChuteIndex == 0) {
		return bookkeeping_data.coin_chute_1_coin;
	}
	return 0;
}

uint32_t CreditBookkeeping_eMoneyCoin_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return bookkeeping_data.emoney_coin;
}

uint32_t CreditBookkeeping_eMoneyCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return bookkeeping_data.emoney_credit;
}

uint32_t CreditBookkeeping_serviceCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return bookkeeping_data.service_credit;
}

uint32_t CreditBookkeeping_totalCoin_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return bookkeeping_data.total_coin;
}

uint32_t CreditBookkeeping_totalCredit_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}
