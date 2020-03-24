#include <stdbool.h>
#include <stdint.h>

#include "log.h"

void* Jvs_getNode(int32_t nodeIndex) {
	log("%d\n", nodeIndex);
	return 0x2F;
}

int32_t Jvs_getNodeCount() {
	log("\n");
	return 0;
}

bool Jvs_isAvailable() {
	log("\n");
	return false;
}
