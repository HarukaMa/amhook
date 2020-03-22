#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

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