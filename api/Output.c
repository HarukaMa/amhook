#include <stdint.h>

#include "log.h"

int32_t OutputId_MaxSize_get() {
	log("\n");
	return 24;
}

void* Output_getPlayer(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return 0;
}

int32_t Output_getPlayerCount() {
	log("\n");
	return 0;
}

void* Output_getSystem() {
	log("\n");
	return 0;
}
