#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

int32_t BoardIO_BoardLedCount_get() {
	log("\n");
	return 2;
}

int32_t BoardIO_DipSwitchCount_get() {
	log("\n");
	return 8;
}

int32_t BoardIO_PushSwitchCount_get() {
	log("\n");
	return 2;
}

uint16_t BoardIO_getCurrentLedStateBits() {
	log("\n");
	return 0;
}

uint16_t BoardIO_getDipSwitchAppValue() {
	log("\n");
	return 0;
}

uint16_t BoardIO_getDipSwitchBits() {
	log("\n");
	return 0;
}

uint16_t BoardIO_getPushSwitchBits() {
	log("\n");
	return 0;
}

bool BoardIO_isCurrentLedStateOn(int32_t index) {
	log("%d\n", index);
	return false;
}

bool BoardIO_isDipSwitchOn(int32_t index) {
	log("%d\n", index);
	return false;
}

bool BoardIO_isPushSwitchOn(int32_t index) {
	log("%d\n", index);
	return false;
}

void BoardIO_setLedState(int32_t index, bool on, bool forceUpdate) {
	log("%d %d %d\n", index, on, forceUpdate);
}
