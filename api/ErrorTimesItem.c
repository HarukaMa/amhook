#include <stdint.h>

#include "log.h"

int32_t ErrorTimesItem_number_get(void *item) {
	log("%p\n", item);
	return 0;
}

int32_t ErrorTimesItem_times_get(void * item) {
	log("%p\n", item);
	return 0;
}
