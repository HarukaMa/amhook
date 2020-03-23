#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

#define _out_

void AimePayDealResult_getAccessCode(void *result, _out_ int8_t *dest, int destSize) {
	log("%p %p %d\n", result, dest, destSize);
}

wchar_t* AimePayDealResult_getErrorCode(void *result) {
	log("%p\n", result);
	return 0;
}

uint32_t AimePayDealResult_getItemCount(void* result) {
	log("%p\n", result);
	return 0;
}

wchar_t* AimePayDealResult_getItemId(void* result) {
	log("%p\n", result);
	return 0;
}

uint64_t AimePayDealResult_getTime(void* result) {
	log("%p\n", result);
	return 0;
}

bool AimePayDealResult_valid(void* result) {
	log("%p\n", result);
	return 0;
}

int32_t MaxAimePayDealResultCount_get() {
	log("\n");
	return 5;
}