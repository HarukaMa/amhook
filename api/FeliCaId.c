#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t FeliCaId_Size_get() {
	log("\n");
	return 16;
}

bool FeliCaId_operator_equals(uint8_t* srcL, int32_t srcLSize, uint8_t* srcR, int32_t srcRSize) {
	log("%p %d %p %d\n", srcL, srcLSize, srcR, srcRSize);
	return false;
}

bool FeliCaId_operator_less(uint8_t* srcL, int32_t srcLSize, uint8_t* srcR, int32_t srcRSize) {
	log("%p %d %p %d\n", srcL, srcLSize, srcR, srcRSize);
	return false;
}

void FeliCaId_toString(uint8_t *src, int32_t srcSize, void (*func)(wchar_t *)) {
	log("%p %d %p\n", src, srcSize, func);
}