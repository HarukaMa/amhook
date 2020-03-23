#include <stdbool.h>
#include <stdint.h>

#include "log.h"

int32_t allnet_MaxWiFiUnitCount_get() {
	log("\n");
	return 10;
}

int32_t allnet_WiFiUnit_getAccessCount(void *unit) {
	log("%p\n", unit);
	return 0;
}

wchar_t* allnet_WiFiUnit_getAuthGoodText(void* unit) {
	log("%p\n", unit);
	return 0;
}

wchar_t* allnet_WiFiUnit_getFirmVersion(void* unit) {
	log("%p\n", unit);
	return 0;
}

wchar_t* allnet_WiFiUnit_getMasterSerial(void* unit) {
	log("%p\n", unit);
	return 0;
}

wchar_t* allnet_WiFiUnit_getSerial(void* unit) {
	log("%p\n", unit);
	return 0;
}

wchar_t* allnet_WiFiUnit_getServerAliveText(void* unit) {
	log("%p\n", unit);
	return 0;
}

bool allnet_WiFiUnit_isAuthGood(void* unit) {
	log("%p\n", unit);
	return false;
}

bool allnet_WiFiUnit_isCache(void* unit) {
	log("%p\n", unit);
	return false;
}

bool allnet_WiFiUnit_isServerAlive(void* unit) {
	log("%p\n", unit);
	return false;
}

bool allnet_WiFiUnit_valid(void* unit) {
	log("%p\n", unit);
	return false;
}
