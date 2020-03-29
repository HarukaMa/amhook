#include <stdint.h>

#include "log.h"

struct CreditBookkeeping {
	int coin_chute_1_coin;
	int emoney_coin;
	int coin_credit;
	int emoney_credit;
	int service_credit;
	int total_coin;

    uint32_t total_time;
};

struct CreditBookkeeping bookkeeping_data;

extern uint32_t total_time;
extern DWORD WINAPI count_total_time(void* _);

void load_bookkeeping_data() {
	FILE* f = fopen("bookkeeping.dat", "rb");
	if (f) {
		fread(&bookkeeping_data, sizeof(struct CreditBookkeeping), 1, f);
		fclose(f);
	}
	total_time = bookkeeping_data.total_time;
	CreateThread(NULL, 0, &count_total_time, NULL, 0, 0);
}

void save_bookkeeping_data() {
	bookkeeping_data.total_time = total_time;
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
