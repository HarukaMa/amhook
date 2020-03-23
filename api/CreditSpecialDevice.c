#include <stdbool.h>

#include "log.h"

bool CreditSpecialDevice_isAvailable(void *device) {
	log("%p\n", device);
	return false;
}

bool CreditSpecialDevice_isLockoutOn(void* device) {
	log("%p\n", device);
	return false;
}

bool CreditSpecialDevice_lockout(void *device, bool on) {
	log("%p %d\n", device, on);
	return false;
}
