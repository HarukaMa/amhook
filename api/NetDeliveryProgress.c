#include <stdint.h>

#include "log.h"

int32_t NetDeliveryProgress_current_get(void *progress) {
	log("%p\n", progress);
	return 0;
}

float NetDeliveryProgress_toPercentage(void* progress) {
	log("%p\n", progress);
	return 0;
}

int32_t NetDeliveryProgress_total_get(void* progress) {
	log("%p\n", progress);
	return 0;
}
