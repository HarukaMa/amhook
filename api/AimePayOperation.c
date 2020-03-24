#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

enum AimePayConfirm {
	None,
	Activation,
	CheckIn
};

bool AimePayOperation_acceptConfirm(void *operation, wchar_t *param) {
	log("%p %ls\n", operation, param);
	return true;
}

bool AimePayOperation_activate(void *operation) {
	log("%p\n", operation);
	return true;
}

bool AimePayOperation_canAddCoin(void* operation, int32_t playerIndex, uint32_t coin) {
	log("%p %d %d\n", operation, playerIndex, coin);
	return true;
}

bool AimePayOperation_canOperateDeal(void* operation) {
	log("%p\n", operation);
	return true;
}

bool AimePayOperation_cancel(void* operation) {
	log("%p\n", operation);
	return true;
}

bool AimePayOperation_checkDisplay(void* operation) {
	log("%p\n", operation);
	return true;
}

bool AimePayOperation_deactivate(void* operation) {
	log("%p\n", operation);
	return true;
}

enum AimePayConfirm AimePayOperation_getConfirm(void* operation) {
	log("%p\n", operation);
	return None;
}

void* AimePayOperation_getDealResult(void* operation) {
	log("%p\n", operation);
	return 0xD;
}

bool AimePayOperation_hasConfirm(void* operation) {
	log("%p\n", operation);
	return false;
}

bool AimePayOperation_hasDealResult(void* operation) {
	log("%p\n", operation);
	return false;
}

bool AimePayOperation_isBusy(void* operation) {
	log("%p\n", operation);
	return false;
}

bool AimePayOperation_isCancellable(void* operation) {
	log("%p\n", operation);
	return true;
}

bool AimePayOperation_isDealAvailable(void* operation) {
	log("%p\n", operation);
	return true;
}

bool AimePayOperation_isErrorOccurred(void* operation) {
	log("%p\n", operation);
	return false;
}

bool AimePayOperation_payAmount(void *operation, uint32_t aimeId, uint8_t* accessCode, int32_t accessCodeSize, wchar_t *itemId, uint32_t count) {
	log("%p %d %p %d %ls %d\n", operation, aimeId, accessCode, accessCodeSize, itemId, count);
	return false;
}

bool AimePayOperation_payToCoin(void *operation, int32_t playerIndex, uint32_t aimeId, uint8_t* accessCode, int32_t accessCodeSize, wchar_t* itemId, uint32_t coin) {
	log("%p %d %p %d %ls %d\n", operation, playerIndex, aimeId, accessCode, accessCodeSize, itemId, coin);
	return false;
}