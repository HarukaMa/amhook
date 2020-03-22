#include <stdbool.h>
#include <stdio.h>

#include "log.h"

double AnalogInput_getValue(void *unit, wchar_t *idValue, double minValue, double maxValue) {
	log("%p %ls %f %f\n", unit, idValue, minValue, maxValue);
	return 0;
}

double AnalogInput_getDelta(void* unit, wchar_t* idValue, double minValue, double maxValue) {
	log("%p %ls %f %f\n", unit, idValue, minValue, maxValue);
	return 0;
}

double AnalogOutput_getCurrentValue(void* unit, wchar_t* idValue, double minValue, double maxValue) {
	log("%p %ls %f %f\n", unit, idValue, minValue, maxValue);
	return 0;
}

void AnalogOutput_setValue(void* unit, wchar_t* idValue, double minValue, double maxValue, double value, bool forceUpdate) {
	log("%p %ls %f %f %f %d\n", unit, idValue, minValue, maxValue, value, forceUpdate);
}

