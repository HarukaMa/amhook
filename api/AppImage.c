#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

bool AppImage_existsOption(wchar_t *optionName) {
	log("%ls\n", optionName);
	return 0;
}

void* AppImage_findOptionInfo(wchar_t *optionName) {
	log("%ls\n", optionName);
	return 0x13;
}

uint64_t AppImage_getCreationTime() {
	log("\n");
	return 0;
}

uint32_t AppImage_getCurrentVersion() {
	log("\n");
	return 0x10500;
}

int32_t AppImage_getOptionCount() {
	log("\n");
	return 0;
}

void* AppImage_getOptionInfo(int32_t index) {
	log("%d\n", index);
	return 0x14;
}

wchar_t* AppImage_getOptionMountRootPath() {
	log("\n");
	return 0;
}

void AppImage_makeOptionMountPath(wchar_t *optionName, void (*func)(intptr_t)) {
	log("%ls %p\n", optionName, func);
}