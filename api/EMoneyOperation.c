#include <stdbool.h>
#include <stdint.h>


#include "log.h"

bool EMoneyOperation_authTerminal(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_canAddCoin(void *operation, int32_t playerIndex, uint32_t coin) {
	log("%p &d &d\n", operation, playerIndex, coin);
	return false;
}

bool EMoneyOperation_canOperateDeal(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_cancel(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_checkDisplay(void* operation) {
	log("%p\n", operation);
	return false;
}

void* EMoneyOperation_getResult(void* operation) {
	log("%p\n", operation);
	return 0;
}

bool EMoneyOperation_hasResult(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_isBusy(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_isCancellable(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_isDealAvailable(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_isErrorOccurred(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_isHeldOver(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_payAmount(void *operation, enum EMoneyBrandId brandId, int32_t amount, int (*hook)) {
	log("%p %d %d %p\n", operation, brandId, amount, hook);
	return false;
}

bool EMoneyOperation_payToCoin(void *operation, int32_t playerIndex, enum EMoneyBrandID brandId, uint32_t coin) {
	log("%p %d %d %d\n", operation, playerIndex, brandId, coin);
	return false;
}

bool EMoneyOperation_removeTerminal(void* operation) {
	log("%p\n", operation);
	return false;
}

bool EMoneyOperation_requestBalance(void* operation, enum EMoneyBrandID brandId) {
	log("%p %d\n", operation, brandId);
	return false;
}
