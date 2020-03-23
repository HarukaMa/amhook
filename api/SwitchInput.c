#include <stdbool.h>

#include "log.h"

bool SwitchInput_isFlipNow(void *unit, wchar_t *idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}

bool SwitchInput_isOffNow(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}

bool SwitchInput_isOn(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}

bool SwitchInput_isOnNow(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}
