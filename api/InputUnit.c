#include <stdbool.h>
#include <stdint.h>


#include "log.h"

bool InputUnit_exists(void *unit, wchar_t *idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}

int64_t InputUnit_getDelta(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

int64_t InputUnit_getDirectValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

int64_t InputUnit_getMaxValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

int64_t InputUnit_getMinValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}

int64_t InputUnit_getValue(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return 0;
}
