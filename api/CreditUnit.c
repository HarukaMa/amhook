#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int current_credits = 0;

struct CreditBookkeeping {
	int coin_chute_1_coin;
	int emoney_coin;
	int coin_credit;
	int emoney_credit;
	int service_credit;
	int total_coin;

	uint32_t total_time;
};

extern struct CreditBookkeeping bookkeeping_data;
extern void save_bookkeeping_data();

extern int32_t(*coin_in_hook)(enum CreditSound sound);
extern int32_t(*coin_in_hook_with_player)(enum CreditSound sound, int32_t *playerIndices, int32_t playerCount);

void service_credit() {
	static int32_t indices[1] = { 0 };
	current_credits += 1;
	if (coin_in_hook) {
		coin_in_hook(2);
	}
	if (coin_in_hook_with_player) {
		coin_in_hook_with_player(2, indices, 1);
	}
	bookkeeping_data.service_credit += 1;
	save_bookkeeping_data();
}

void insert_coin() {
	static int32_t indices[1] = { 0 };
	current_credits += 1;
	if (coin_in_hook) {
		coin_in_hook(1);
	}
	if (coin_in_hook_with_player) {
		coin_in_hook_with_player(1, indices, 1);
	}
	bookkeeping_data.coin_chute_1_coin += 1;
	bookkeeping_data.total_coin += 1;
	bookkeeping_data.coin_credit += 1;
	save_bookkeeping_data();
}

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
	return current_credits;
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
	return current_credits >= count;
}

bool CreditUnit_isZero(void* unit) {
	log("%p\n", unit);
	return false;
}

bool CreditUnit_payGameCost(void* unit, int32_t gameCostIndex, int32_t count) {
	log("%p %d %d\n", unit, gameCostIndex, count);
	current_credits -= count;
	return true;
}

wchar_t* CreditUnit_toString(void* unit) {
	log("%p\n", unit);
	return 0;
}
