#include <stdbool.h>
#include <stdint.h>

#include "log.h"

void allnet_WiFi_clearUnitCache() {
	log("\n");
}

void* allnet_WiFi_getUnit(int32_t unitIndex) {
	log("%d\n", unitIndex);
	return 0;
}

int32_t allnet_WiFi_getUnitCount() {
	log("\n");
	return 0;
}

bool allnet_WiFi_isAvailable() {
	log("\n");
	return false;
}

bool allnet_WiFi_isUnitCacheSaved() {
	log("\n");
	return false;
}

void allnet_WiFi_saveUnitCache() {
	log("\n");
}