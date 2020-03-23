#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t JvsSwitchInput_MaxPlayerBitCount_get() {
	log("\n");
	return 64;
}

int32_t JvsSwitchInput_MaxSystemBitCount_get() {
	log("\n");
	return 8;
}

uint64_t JvsSwitchInput_getPlayerBits(void *input, int32_t playerIndex) {
	log("%p %d\n", input, playerIndex);
	return 0;
}

int32_t JvsSwitchInput_getPlayerCount(void* input) {
	log("%p\n", input);
	return 0;
}

uint16_t JvsSwitchInput_getSystemBits(void* input) {
	log("%p\n", input);
	return 0;
}

bool JvsSwitchInput_isPlayerOn(void *input, int32_t playerIndex, int32_t bitIndex) {
	log("%p %d %d\n", input, playerIndex, bitIndex);
	return 0;
}

bool JvsSwitchInput_isSystemOn(void* input, int32_t bitIndex) {
	log("%p %d\n", input, bitIndex);
	return 0;
}
