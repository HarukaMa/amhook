#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum ErrorResetType {
	None,
	Any,
	Shutdown,
	Operation,
	Test
};

wchar_t* ErrorInfo_getMessage(void *info) {
	log("%p\n", info);
	return 0;
}

int32_t ErrorInfo_getNumber(void* info) {
	log("%p\n", info);
	return 0;
}

enum ErrorResetType ErrorInfo_getResetType(void* info) {
	log("%p\n", info);
	return None;
}

int32_t ErrorInfo_getSubNumber(void* info) {
	log("%p\n", info);
	return 0;
}

uint64_t ErrorInfo_getTime(void* info) {
	log("%p\n", info);
	return 0;
}

bool ErrorInfo_isOccurred(void* info) {
	log("%p\n", info);
	return false;
}

void* ErrorInfo_toString(void *info, void (*func)(wchar_t *)) {
	log("%p %p\n", info, func);
	return 0;
}
