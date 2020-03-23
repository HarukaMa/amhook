#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum CreditSound {
	None,
	Coin,
	Credit
};

bool Credit_clearBackup() {
	log("\n");
	return false;
}

void* Credit_getBookkeeping() {
	log("\n");
	return 0;
}

void* Credit_getConfig() {
	log("\n");
	return 0;
}

void* Credit_getPlayer(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return 0;
}

int32_t Credit_getPlayerCount() {
	log("\n");
	return 1;
}

void* Credit_getSpecialDevice() {
	log("\n");
	return 0;
}

bool Credit_isAvailable() {
	log("\n");
	return false;
}

bool Credit_isCoinInIgnored() {
	log("\n");
	return false;
}

void Credit_resetCoinInHook() {
	log("\n");
}

void Credit_setCoinInHook(int32_t (*hook)(enum CreditSound sound)) {
	log("%p\n", hook);
}

void Credit_setCoinInHookWithPlayer(int32_t (*hook)(enum CreditSound sound, intptr_t playerIndices, int32_t playerCount)) {
	log("%p\n", hook);
}

bool Credit_setCoinInIgnored(bool ignored) {
	log("%d\n", ignored);
	return false;
}
