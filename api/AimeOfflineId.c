#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

#define _out_

enum AimeOfflineIdType {
	None,
	AccessCode,
	FeliCaId
};

int32_t AimeOfflineId_Size_get() {
	log("\n");
	return 17;
}

void AimeOfflineId_getData_accessCode_get(uint8_t *src, int32_t srcSize, _out_ uint8_t *dest, int32_t destSize) {
	log("%p %d %p %d\n", src, srcSize, dest, destSize);
}

void AimeOfflineId_getData_feliCaId_get(uint8_t* src, int32_t srcSize, _out_ uint8_t* dest, int32_t destSize) {
	log("%p %d %p %d\n", src, srcSize, dest, destSize);
}

enum AimeOfflineIdType AimeOfflineId_getType(void *src, int srcSize) {
	log("%p %d\n", src, srcSize);
	return None;
}

void AimeOfflineId_make_AccessCode(uint8_t *src, int srcSize, _out_ uint8_t *dest, int32_t destSize) {
	log("%p %d %p %d\n", src, srcSize, dest, destSize);
}

void AimeOfflineId_make_FeliCaId(uint8_t* src, int srcSize, _out_ uint8_t* dest, int32_t destSize) {
	log("%p %d %p %d\n", src, srcSize, dest, destSize);
}

bool AimeOfflineId_operator_equals(uint8_t* srcL, int32_t srcLSize, uint8_t* srcR, int32_t srcRSize) {
	log("%p %d %p %d\n", srcL, srcLSize, srcR, srcRSize);
	return false;
}

bool AimeOfflineId_operator_less(uint8_t* srcL, int32_t srcLSize, uint8_t* srcR, int32_t srcRSize) {
	log("%p %d %p %d\n", srcL, srcLSize, srcR, srcRSize);
	return false;
}

void AimeOfflineId_toString(uint8_t* src, int32_t srcSize, wchar_t* separator, void (*func)(intptr_t)) {
	log("%p %d %ls %p\n", src, srcSize, separator, func);
}

bool AimeOfflineId_valid(uint8_t* src, int32_t srcSize) {
	log("%p %d\n", src, srcSize);
	return false;
}