#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum LineType {
	Unknown,
	Broadband,
	Mobile,
	Xdsl
};

wchar_t* allnet_Auth_getCountryCode() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getGameServerHost() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getGameServerUri() {
	log("\n");
	return 0;
}

enum LineType allnet_Auth_getLineType() {
	log("\n");
	return Unknown;
}

uint32_t allnet_Auth_getLocationId() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getLocationName() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getLocationNickname(int32_t partIndex) {
	log("%d\n", partIndex);
	return 0;
}

int32_t allnet_Auth_getLocationNicknamePartCount() {
	log("\n");
	return 0;
}

int32_t allnet_Auth_getRegionCode() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getRegionName(int32_t partIndex) {
	log("%d\n", partIndex);
	return 0;
}

int32_t allnet_Auth_getRegionNamePartCount() {
	log("\n");
	return 0;
}

bool allnet_Auth_isAvailable() {
	log("\n");
	return false;
}

bool allnet_Auth_isDevelop() {
	log("\n");
	return false;
}

bool allnet_Auth_isGood() {
	log("\n");
	return false;
}
