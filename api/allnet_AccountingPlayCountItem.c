#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t allnet_AccountingPlayCountItem_count_get(void *item) {
	log("%p\n", item);
	return 0;
}

uint64_t allnet_AccountingPlayCountItem_month_get(void* item) {
	log("%p\n", item);
	return 0;
}

void allnet_AccountingPlayCountItem_toString(void *item, int32_t countWidth, void (*func)(wchar_t*)) {
	log("%p %d %p\n", item, countWidth, func);
}

bool allnet_AccountingPlayCountItem_valid(void* item) {
	log("%p\n", item);
	return true;
}
