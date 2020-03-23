#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t ErrorNumberLimit_get() {
	log("\n");
	return 0xFFFF;
}

int32_t ErrorSubNumberLimit_get() {
	log("\n");
	return 999;
}

bool Error_canReset() {
	log("\n");
	return false;
}

bool Error_clearLog() {
	log("\n");
	return false;
}

void* Error_getInfo() {
	log("\n");
	return 0;
}

void* Error_getLog() {
	log("\n");
	return 0;
}

bool Error_reset() {
	log("\n");
	return false;
}

bool Error_set(int32_t number, int32_t subNumber) {
	log("%d %d\n", number, subNumber);
	return false;
}
