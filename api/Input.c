#include <stdint.h>

#include "log.h"

int32_t InputId_MaxSize_get() {
	log("\n");
	return 24;
}

void* Input_getPlayer(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return 0x2D;
}

int32_t Input_getPlayerCount() {
	log("\n");
	return 1;
}

void* Input_getSystem() {
	log("\n");
	return 0x2E;
}
