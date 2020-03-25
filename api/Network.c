#include <stdbool.h>

#include "log.h"

bool Network_canStartTest() {
	log("\n");
	return true;
}

void* Network_getPowerOnTestInfo() {
	log("\n");
	return 0x3B;
}

void* Network_getProperty() {
	log("\n");
	return 0x3C;
}

void* Network_getTestInfo() {
	log("\n");
	return 0x3D;
}

bool Network_isAvailable() {
	log("\n");
	return true;
}

bool Network_isLanAvailable() {
	log("\n");
	return true;
}

bool Network_isLocationLanAvailable() {
	log("\n");
	return true;
}

bool Network_isWanAvailable() {
	log("\n");
	return true;
}

bool Network_startTest() {
	log("\n");
	return true;
}
