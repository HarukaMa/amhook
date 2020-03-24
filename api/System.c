#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum RegionCode {
	Unknown,
	Japan,
	China,
	Export
};

wchar_t* System_getAppRootPath() {
	log("\n");
	return 0;
}

void* System_getBoardId() {
	log("\n");
	return 0x43;
}

wchar_t* System_getGameId() {
	log("\n");
	return L"GAME";
}

void* System_getKeychipId() {
	log("\n");
	return 0x44;
}

uint32_t System_getModelType() {
	log("\n");
	return 0;
}

enum RegionCode System_getRegionCode() {
	log("\n");
	return Japan;
}

void* System_getResolution(int monitorIndex) {
	log("%d\n", monitorIndex);
	return 0x45;
}

bool System_isDevelop() {
	log("\n");
	return false;
}