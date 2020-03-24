#include <stdint.h>

#include "log.h"

enum NetDeliveryStatus {
	Unknown,
	Error,
	NotStart,
	Download,
	Complete,
	UpdateReady,
	UpToDate,
	Retry
};

uint64_t NetDeliveryAppImageInfo_creationTime_get(void *info) {
	log("%p\n", info);
	return 0;
}

void* NetDeliveryAppImageInfo_progress_get(void* info) {
	log("%p\n", info);
	return 0x38;
}

enum NetDeliveryStatus NetDeliveryAppImageInfo_status_get(void* info) {
	log("%p\n", info);
	return 0;
}

uint32_t NetDeliveryAppImageInfo_version_get(void* info) {
	log("%p\n", info);
	return 0;
}
