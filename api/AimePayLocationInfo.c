#include <stdbool.h>
#include <stdio.h>

wchar_t* AimePayLocationInfo_getCompanyName(void *info) {
	log("%p\n", info);
	return 0;
}

wchar_t AimePayLocationInfo_getName(void* info) {
	log("%p\n", info);
	return 0;
}

bool AimePayLocationInfo_valid(void* info) {
	log("%p\n", info);
	return false;
}
