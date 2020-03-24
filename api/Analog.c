#include <stdbool.h>
#include <stdio.h>

#include "log.h"

int mouse_last_x = 0;
double analog_value = 0;
double analog_delta = 0;

LRESULT switch_input_mouse_proc(int code, WPARAM wparam, LPARAM lparam) {
	if (code < 0) {
		return CallNextHookEx(0, code, wparam, lparam);
	}
	MOUSEHOOKSTRUCT* param = (MOUSEHOOKSTRUCT*)lparam;
	int x = param->pt.x;
	double d = mouse_last_x - x;
	mouse_last_x = x;
	analog_delta = d / 500;
	analog_value += analog_delta;
	if (analog_value < -1) {
		analog_value = -1;
	} else if (analog_value > 1) {
		analog_value = 1;
	}
	return CallNextHookEx(0, code, wparam, lparam);
}

double AnalogInput_getValue(void *unit, wchar_t *idValue, double minValue, double maxValue) {
	log("%p %ls %f %f\n", unit, idValue, minValue, maxValue);
	return analog_value;
}

double AnalogInput_getDelta(void* unit, wchar_t* idValue, double minValue, double maxValue) {
	log("%p %ls %f %f\n", unit, idValue, minValue, maxValue);
	return analog_delta;
}

double AnalogOutput_getCurrentValue(void* unit, wchar_t* idValue, double minValue, double maxValue) {
	log("%p %ls %f %f\n", unit, idValue, minValue, maxValue);
	return 0;
}

void AnalogOutput_setValue(void* unit, wchar_t* idValue, double minValue, double maxValue, double value, bool forceUpdate) {
	log("%p %ls %f %f %f %d\n", unit, idValue, minValue, maxValue, value, forceUpdate);
}

