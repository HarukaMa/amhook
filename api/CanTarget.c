#include <stdint.h>
#include <stdio.h>

#include "log.h"

void* CanTarget_getAck(void *target, uint8_t command) {
	log("%p %d\n", target, command);
	return 0;
}

void* CanTarget_getProperty(void* target) {
	log("%p\n", target);
	return 0;
}

void* CanTarget_send(void *target, uint8_t command, uint8_t *data, int32_t dataSize, uint8_t priority) {
	log("%p %d %p %d %d\n", target, command, data, dataSize, priority);
	return 0;
}