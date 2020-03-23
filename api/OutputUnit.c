#include <stdbool.h>
#include <stdint.h>

#include "log.h"

bool OutputUnit_exists(void *unit, wchar_t *idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}

int64_t OutputUnit_getCurrentValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

int64_t OutputUnit_getMaxValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

int64_t OutputUnit_getMinValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

void OutputUnit_setValue(void* unit, wchar_t* idValue, int64_t value, bool forceUpdate) {
	log("%p %ls %d %d\n", unit, idValue, value, forceUpdate);
}
