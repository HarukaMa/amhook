#include "log.h"

void NetDeliveryOptionImageInfo_calcTotalProgress(void *info, void (*func)(intptr_t)) {
	log("%p %p\n", info, func);
}

void* NetDeliveryOptionImageInfo_optionalProgress_get(void *info) {
	log("%p\n", info);
	return 0;
}

void* NetDeliveryOptionImageInfo_progress_get(void* info) {
	log("%p\n", info);
	return 0;
}

enum NetDeliveryStatus NetDeliveryOptionImageInfo_status_get(void* info) {
	log("%p\n", info);
	return 0;
}
