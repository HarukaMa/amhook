#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

#define _out_

void AimeResult_getAccessCode(void *result, _out_ uint8_t *dest, int destSize) {
	log("%p %p %d\n", result, dest, destSize);
}

uint32_t AimeResult_getAimeId(void *result) {
	log("%p\n", result);
	return 0;
}

wchar_t* AimeResult_getFirmVersion(void *unit) {
	log("%p\n", unit);
	return 0;
}

wchar_t* AimeResult_getHardVersion(void* unit) {
	log("%p\n", unit);
	return 0;
}

void AimeResult_getOfflineId(void *result, _out_ uint8_t *dest, int32_t destSize) {
	log("%p %p %d\n", result, dest, destSize);
}

uint32_t AimeResult_getRelatedAimeId(void *result, int32_t index) {
	log("%p %d\n", result, index);
	return 0;
}

int32_t AimeResult_getRelatedAimeIdCount(void *result) {
	log("%p\n", result);
	return 0;
}

wchar_t* AimeResult_getSegaIdAuthKey(void *result) {
	log("%p\n", result);
	return 0;
}

bool AimeResult_isMobile(void* result) {
	log("%p\n", result);
	return false;
}

bool AimeResult_isReaderDetected(void* result) {
	log("%p\n", result);
	return false;
}

bool AimeResult_isSegaIdRegistered(void* result) {
	log("%p\n", result);
	return false;
}

bool AimeResult_valid(void* result) {
	log("%p\n", result);
	return false;
}