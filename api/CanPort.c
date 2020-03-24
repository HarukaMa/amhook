#include <stdint.h>
#include <stdio.h>

#include "log.h"

void* CanPort_getTarget(void *port, int targetIndex) {
	log("%p %d\n", port, targetIndex);
	return 0x19;
}

int32_t CanPort_getTargetCount(void *port) {
	log("%p\n", port);
	return 0;
}
