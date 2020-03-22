#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

enum CanTargetType {
	Host,
	Motor,
	Sensor,
	IO,
	Led,
	Reserved
};

wchar_t* CanTargetProperty_getCustomChip(void *property) {
	log("%p\n", property);
	return 0;
}

uint16_t CanTargetProperty_getFirmRevision(void* property) {
	log("%p\n", property);
	return 0;
}

uint16_t CanTargetProperty_getFirmSum(void* property) {
	log("%p\n", property);
	return 0;
}

uint16_t CanTargetProperty_getId(void* property) {
	log("%p\n", property);
	return 0;
}

wchar_t* CanTargetProperty_getProduct(void* property) {
	log("%p\n", property);
	return 0;
}

enum CanTargetType CanTargetProperty_getType(void* property) {
	log("%p\n", property);
	return Reserved;
}

bool CanTargetProperty_valid(void* property) {
	log("%p\n", property);
	return false;
}