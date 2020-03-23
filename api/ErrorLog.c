#include <stdint.h>

#include "log.h"

void* ErrorLog_findTimesItem(void *_log, int32_t number) {
	log("%p %d\n", _log, number);
	return 0;
}

void* ErrorLog_getHistoryItem(void * _log, int32_t index) {
	log("%p %d\n", _log, index);
	return 0;
}

int32_t ErrorLog_getHistoryItemCount(void* _log) {
	log("%p\n", _log);
	return 0;
}

void* ErrorLog_getTimesItem(void* _log, int32_t index) {
	log("%p %d\n", _log, index);
	return 0;
}

int32_t ErrorLog_getTimesItemCount(void* _log) {
	log("%p\n", _log);
	return 0;
}

