#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

#define _out_

enum CanErrorReport {
	None,
	Busy,
	Unsupported,
	InvalidParam,
	Fail,
	Reserved_05,
	Reserved_06,
	Reserved_07,
	Reserved_08,
	Reserved_09,
	Reserved_0A,
	Reserved_0B,
	Reserved_0C,
	Reserved_0D,
	Reserved_0E,
	Unknown
};

bool CanAck_exists(void *ack) {
	log("%p\n", ack);
	return false;
}

uint8_t CanAck_getCommand(void *ack) {
	log("%p\n", ack);
	return 0;
}

int32_t CanAck_getData(void *ack, _out_ uint8_t *dest, int32_t destSize) {
	log("%p %p %d\n", ack, dest, destSize);
	return 0;
}

int32_t CanAck_getDataSize(void* ack) {
	log("%p\n", ack);
	return 0;
}

enum CanErrorReport CanAck_getErrorReport(void* ack) {
	log("%p\n", ack);
	return Unknown;
}

bool CanAck_isError(void* ack) {
	log("%p\n", ack);
	return 0;
}

