#include <stdbool.h>
#include <stdint.h>

#include "log.h"

uint64_t OptionImageInfo_creationTime_get(void *info) {
	log("%p\n", info);
	return false;
}

wchar_t* OptionImageInfo_name_get(void* info) {
	log("%p\n", info);
	return false;
}
