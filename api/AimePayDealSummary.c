#include <stdint.h>
#include <stdio.h>

#include "log.h"

uint32_t AimePayDealSummary_getAmount(void *summary) {
	log("%p\n", summary);
	return 0;
}

uint32_t AimePayDealSummary_getCount(void* summary) {
	log("%p\n", summary);
	return 0;
}

uint64_t AimePayDealSummary_getDate(void* summary) {
	log("%p\n", summary);
	return 0;
}

int32_t MaxAimePayDealSummaryCount_get() {
	log("\n");
	return 7;
}