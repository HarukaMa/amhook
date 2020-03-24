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
	if (!wcscmp(idValue, L"switch_player_1_15") || !wcscmp(idValue, L"switch_player_0_14")) {
		return true;
	}
	return false;
}

bool SwitchInput_isOnNow(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}
