#include <stdint.h>

#include "log.h"

int32_t JvsAnalogInput_getChannelCount(void *input) {
	log("%p\n", input);
	return 0;
}

int32_t JvsAnalogInput_getValidBitCount(void* input) {
	log("%p\n", input);
	return 0;
}

uint16_t JvsAnalogInput_getValue(void* input, int32_t channelIndex) {
	log("%p %d\n", input, channelIndex);
	return 0;
}