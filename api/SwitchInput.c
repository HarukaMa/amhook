#include <stdbool.h>

#include "log.h"

bool switch_input_states[14] = { false };

extern void service_credit();
extern void insert_coin();
extern bool aime_unit_has_card;

LRESULT switch_input_keyboard_proc(int code, WPARAM wparam, LPARAM lparam) {
    if (code < 0) {
		return CallNextHookEx(0, code, wparam, lparam);
    }
	switch (wparam) {
	case VK_F1:
		switch_input_states[0] = lparam & 0x80000000 ? false : true;
		break;
	case VK_F2:
		switch_input_states[1] = lparam & 0x80000000 ? false : true;
		if (switch_input_states[1] && !(lparam & 0x40000000)) {
			service_credit();
		}
		break;
	case VK_F3:
		switch_input_states[2] = lparam & 0x80000000 ? false : true;
		break;
	case VK_F4:
		switch_input_states[3] = lparam & 0x80000000 ? false : true;
		break;
	case 'S':
		switch_input_states[4] = lparam & 0x80000000 ? false : true;
		break;
	case 'D':
		switch_input_states[5] = lparam & 0x80000000 ? false : true;
		break;
	case 'F':
		switch_input_states[6] = lparam & 0x80000000 ? false : true;
		break;
	case 'G':
		switch_input_states[7] = lparam & 0x80000000 ? false : true;
		break;
	case 'H':
		switch_input_states[8] = lparam & 0x80000000 ? false : true;
		break;
	case 'J':
		switch_input_states[9] = lparam & 0x80000000 ? false : true;
		break;
	case 'K':
		switch_input_states[10] = lparam & 0x80000000 ? false : true;
		break;
	case 'L':
		switch_input_states[11] = lparam & 0x80000000 ? false : true;
		break;
	case VK_F6:
		switch_input_states[12] = lparam & 0x80000000 ? false : true;
		break;
	case VK_F5:
		switch_input_states[13] = lparam & 0x80000000 ? false : true;
		break;

	case VK_RETURN:
		if (!(lparam & 0x80000000) && !(lparam & 0x40000000)) {
			insert_coin();
		}
		break;

	case VK_BACK:
		aime_unit_has_card = lparam & 0x80000000 ? false : true;
		break;
	}
	
	return CallNextHookEx(0, code, wparam, lparam);
}

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
	if (!wcscmp(idValue, L"switch_system_00")) {
		return switch_input_states[0];
	}
	if (!wcscmp(idValue, L"switch_player_0_06")) {
		return switch_input_states[1];
	}
	if (!wcscmp(idValue, L"switch_push_00")) {
		return switch_input_states[2];
	}
	if (!wcscmp(idValue, L"switch_push_01")) {
		return switch_input_states[3];
	}
	if (!wcscmp(idValue, L"switch_player_1_15")) {
		return !switch_input_states[4];
	}
	if (!wcscmp(idValue, L"switch_player_0_00")) {
		return switch_input_states[5];
	}
	if (!wcscmp(idValue, L"switch_player_0_05")) {
		return switch_input_states[6];
	}
	if (!wcscmp(idValue, L"switch_player_0_04")) {
		return switch_input_states[7];
	}
	if (!wcscmp(idValue, L"switch_player_0_01")) {
		return switch_input_states[8];
	}
	if (!wcscmp(idValue, L"switch_player_1_00")) {
		return switch_input_states[9];
	}
	if (!wcscmp(idValue, L"switch_player_0_15")) {
		return switch_input_states[10];
	}
	if (!wcscmp(idValue, L"switch_player_0_14")) {
		return !switch_input_states[11];
	}
	if (!wcscmp(idValue, L"switch_player_0_13")) {
		return switch_input_states[12];
	}
	if (!wcscmp(idValue, L"switch_player_1_14")) {
		return switch_input_states[13];
	}
	return false;
}

bool SwitchInput_isOnNow(void* unit, wchar_t* idValue) {
	log("%p %ls\n", unit, idValue);
	return false;
}
