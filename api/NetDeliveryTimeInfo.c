#include <stdbool.h>
#include <stdint.h>


#include "log.h"

bool NetDeliveryTimeInfo_existsImage(void *info) {
	log("%p\n", info);
	return false;
}

uint64_t NetDeliveryTimeInfo_order_get(void* info) {
	log("%p\n", info);
	return false;
}

uint64_t NetDeliveryTimeInfo_release_get(void* info) {
	log("%p\n", info);
	return false;
}
