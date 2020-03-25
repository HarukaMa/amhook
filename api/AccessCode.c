#include <stdbool.h>
#include <stdint.h>
#include "log.h"

#define _out_


int32_t AccessCode_DigitCount_get() {
	log("\n");
	return 20;
}

int32_t AccessCode_Size_get() {
	log("\n");
	return 20; // should be 10 but well
}

bool AccessCode_canMake(wchar_t *src, wchar_t *separator) {
	log("%ls %ls\n", src, separator);
	return false;
}

int32_t AccessCode_getDigit(uint8_t *src, int32_t srcSize, int32_t digitIndex) {
	log("%p %d %d\n", src, srcSize, digitIndex);
	return -1;
}

void AccessCode_make(wchar_t *src, wchar_t *separator, _out_ uint8_t *dest, int32_t destSize) {
	log("%ls %ls %p %d\n", src, separator, dest, destSize);
}

void AccessCode_makeInvalid(_out_ uint8_t *dest, int32_t destSize) {
	log("%p %d\n", dest, destSize);
}

bool AccessCode_operator_equals(uint8_t *srcL, int32_t srcLSize, uint8_t *srcR, int32_t srcRSize) {
	log("%p %d %p %d\n", srcL, srcLSize, srcR, srcRSize);
	return false;
}

bool AccessCode_operator_less(uint8_t* srcL, int32_t srcLSize, uint8_t* srcR, int32_t srcRSize) {
	log("%p %d %p %d\n", srcL, srcLSize, srcR, srcRSize);
	return false;
}

void AccessCode_toString(uint8_t *src, int32_t srcSize, wchar_t *separator, void (*func)(wchar_t *)) {
	log("%p %d %ls %p\n", src, srcSize, separator, func);
	static wchar_t string[21];
	swprintf(string, 21, L"%hs", src);
	func(string);
}

bool AccessCode_valid(uint8_t *src, int32_t srcSize) {
	log("%p %d\n", src, srcSize);
	if (srcSize <= 0 || srcSize > 20) {
		return false;
	}
	if (src[0] == 0) {
		return false;
	}
	return true;
}