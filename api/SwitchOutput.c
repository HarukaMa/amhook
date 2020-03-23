#include <stdbool.h>
#include <stdint.h>


#include "log.h"

bool SwitchOutput_isCurrentOn(void *unit, wchar_t *idValue, int32_t bitIndex) {
	log("%p %ls %d\n", unit, idValue, bitIndex);
	return false;
}

void SwitchOutput_reset(void* unit, wchar_t* idValue, int32_t bitIndex, bool forceUpdate) {
	log("%p %ls %d %d\n", unit, idValue, bitIndex, forceUpdate);
}

void SwitchOutput_set(void* unit, wchar_t* idValue, int32_t bitIndex, bool on, bool forceUpdate) {
	log("%p %ls %d %d %d\n", unit, idValue, bitIndex, on, forceUpdate);
}
