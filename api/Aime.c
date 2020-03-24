#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

enum AimeLogStatus {
	Enter,
	Continue,
	Leave
};

void* Aime_getCampaignInfo(int32_t index) {
	log("%d\n", index);
	return 0x1;
}

int32_t Aime_getCampaignInfoCount() {
	log("\n");
	return 0;
}

void* Aime_getCampaignProgress(uint32_t aimeId, int32_t index) {
	log("%d %d\n", aimeId, index);
	return 0x2;
}

int32_t Aime_getCampaignProgressCount(uint32_t aimeId) {
	log("%d\n", aimeId);
	return 0;
}

float Aime_getFirmUpdateProgress() {
	log("\n");
	return 0;
}

void* Aime_getUnit(int32_t unitIndex) {
	log("%d\n", unitIndex);
	return 0x3;
}

int32_t Aime_getUnitCount() {
	log("\n");
	return 1;
}

bool Aime_isAvailable() {
	log("\n");
	return true;
}

bool Aime_isDBAlive() {
	log("\n");
	return true;
}

bool Aime_isFirmUpdating() {
	log("\n");
	return false;
}

void* Aime_requestCampaignProgress(uint32_t aimeId) {
	log("%d\n", aimeId);
	return 0x4;
}

void* Aime_requestCampaignProgress_lastResult(uint32_t aimeId) {
	log("%d\n", aimeId);
	return 0x5;
}

void* Aime_sendLog(uint32_t aimeId, enum AimeLogStatus status, int32_t gameCostIndex, int32_t gameCostCount) {
	log("%d %d %d %d", aimeId, status, gameCostIndex, gameCostCount);
	return 0x6;
}