#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum NetworkTestItem {
	IpAddress,
	Gateway,
	LanDns,
	Hops,
	LineType,
	AllnetAuth,
	Aime,
	EMoney,
	AimePay
};

enum TestResult {
	ResultNone,
	NA,
	Good,
	Bad
};

enum NetworkTestState {
	StateNone,
	Busy,
	Done
};

enum NetworkTestItem NetworkTestInfo_getAvailableItem(void *info, int32_t index) {
	log("%p %d\n", info, index);
	return IpAddress;
}

int32_t NetworkTestInfo_getAvailableItemCount(void* info) {
	log("%p\n", info);
	return 0;
}

wchar_t* NetworkTestInfo_getBusyStatusText(bool blink) {
	log("%d\n", blink);
	return 0;
}

void* NetworkTestInfo_getErrorInfo(void* info) {
	log("%p\n", info);
	return 0;
}

int32_t NetworkTestInfo_getHops(void* info) {
	log("%p\n", info);
	return 0;
}

enum TestResult NetworkTestInfo_getResult(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return ResultNone;
}

enum NetworkTestState NetworkTestInfo_getState(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return StateNone;
}

wchar_t* NetworkTestInfo_getStatusText(void* info, enum NetworkTestItem item, bool blinkBusy) {
	log("%p %d %d\n", info, item, blinkBusy);
	return 0;
}

bool NetworkTestInfo_isAvailableItem(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return false;
}

bool NetworkTestInfo_isBusy(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return false;
}

bool NetworkTestInfo_isCompleted(void* info) {
	log("%p\n", info);
	return 0;
}

bool NetworkTestInfo_isDone(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return false;
}

bool NetworkTestInfo_isRunning(void* info, enum NetworkTestItem item) {
	log("%p %d\n", info, item);
	return false;
}
