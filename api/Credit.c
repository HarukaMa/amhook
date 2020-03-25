#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum CreditSound {
	None,
	Coin,
	Credit
};

int32_t(*coin_in_hook)(enum CreditSound sound) = NULL;
int32_t(*coin_in_hook_with_player)(enum CreditSound sound, intptr_t playerIndices, int32_t playerCount) = NULL;

bool Credit_clearBackup() {
	log("\n");
	return false;
}

void* Credit_getBookkeeping() {
	log("\n");
	return 0x1D;
}

void* Credit_getConfig() {
	log("\n");
	return 0x1E;
}

void* Credit_getPlayer(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return 0x20;
}

int32_t Credit_getPlayerCount() {
	log("\n");
	return 1;
}

void* Credit_getSpecialDevice() {
	log("\n");
	return 0x21;
}

bool Credit_isAvailable() {
	log("\n");
	return true;
}

bool Credit_isCoinInIgnored() {
	log("\n");
	return false;
}

void Credit_resetCoinInHook() {
	log("\n");
	coin_in_hook = NULL;
}

void Credit_setCoinInHook(int32_t (*hook)(enum CreditSound sound)) {
	log("%p\n", hook);
	coin_in_hook = hook;
}

void Credit_setCoinInHookWithPlayer(int32_t (*hook)(enum CreditSound sound, intptr_t playerIndices, int32_t playerCount)) {
	log("%p %\n", hook);
	coin_in_hook = hook;
}

bool Credit_setCoinInIgnored(bool ignored) {
	log("%d\n", ignored);
	return false;
}
