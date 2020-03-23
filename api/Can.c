#include <stdbool.h>
#include <stdint.h>

#include "log.h"

void* Can_getPort(int portIndex) {
	log("%d\n", portIndex);
	return 0;
}

int32_t Can_getPortCount() {
	log("\n");
	return 0;
}

bool Can_isAvailable() {
	log("\n");
	return false;
}

uint8_t DefaultCanPacketPriority_get() {
	log("\n");
	return 15;
}

int32_t MaxCanPacketDataSize_get() {
	log("\n");
	return 8;
}

uint8_t MaxCanPacketPriority_get() {
	log("\n");
	return 15;
}
