#include <stdint.h>

#include "log.h"

int32_t TimeHistogramItem_count_get(void *item) {
	log("%p\n", item);
	return 0;
}

uint32_t TimeHistogramItem_timeRangeMax_get(void* item) {
	log("%p\n", item);
	return 0;
}

uint32_t TimeHistogramItem_timeRangeMin_get(void* item) {
	log("%p\n", item);
	return 0;
}
