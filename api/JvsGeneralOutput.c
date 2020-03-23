#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t JvsGeneralOutput_MaxBitCount_get() {
	log("\n");
	return 64;
}

uint64_t JvsGeneralOutput_getCurrentBits(void *output) {
	log("%p\n", output);
	return 0;
}

void JvsGeneralOutput_resetBits(void *output, bool forceUpdate) {
	log("%p %d\n", output, forceUpdate);
}

void JvsGeneralOutput_setBit(void *output, int32_t bitIndex, bool on, bool forceUpdate) {
	log("%p %d %d %d\n", output, bitIndex, on, forceUpdate);
}

void JvsGeneralOutput_setBits(void *output, uint64_t bits, bool forceUpdate) {
	log("%p %llu %d\n", output, bits, forceUpdate);
}

