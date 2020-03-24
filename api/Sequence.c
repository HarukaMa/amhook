#include <stdbool.h>
#include <stdint.h>

#include "log.h"

#define _out_

enum PlayErrorId {
	None,
	InvalidParam,
	InvalidState,
	CreditPay,
	AccountingBegin,
	AccountingEnd
};

enum PlayAccountingTiming {
	Normal,
	AtBegin,
	AtEnd
};

static bool in_test = false;
static bool in_play = false;

bool Sequence_beginPlay(int32_t playerIndex, int32_t gameCostIndex, int32_t gameCostCount, bool accountingBeginValid, int32_t accountBeginKindCode,
	int32_t accountingBeginStatusCode, bool accountingEndValid, int32_t accountingEndKindCode, int32_t accountingEndStatusCode, int32_t accountingEndItemCount,
	uint32_t aimeId, _out_ enum PlayErrorId errorId) {
	log("%d %d %d %d %d %d %d %d %d %d %d %p\n", playerIndex, gameCostIndex, gameCostCount, accountingBeginValid, accountBeginKindCode, accountingBeginStatusCode,
		accountingEndValid, accountingEndKindCode, accountingEndStatusCode, accountingEndItemCount, aimeId, errorId);
	in_play = true;
	return true;
}

bool Sequence_beginTest() {
	log("\n");
	in_test = true;
	return true;
}

bool Sequence_clearBackup() {
	log("\n");
	return false;
}

bool Sequence_continuePlay(int32_t playerIndex, int32_t gameCostIndex, int32_t gameCostCount, bool accountingBeginValid, int32_t accountBeginKindCode,
	int32_t accountingBeginStatusCode, bool accountingEndValid, int32_t accountingEndKindCode, int32_t accountingEndStatusCode, int32_t accountingEndItemCount,
	_out_ enum PlayErrorId errorId) {
	log("%d %d %d %d %d %d %d %d %d %d %p\n", playerIndex, gameCostIndex, gameCostCount, accountingBeginValid, accountBeginKindCode, accountingBeginStatusCode,
		accountingEndValid, accountingEndKindCode, accountingEndStatusCode, accountingEndItemCount, errorId);
	return false;
}

bool Sequence_endPlay(int32_t playerIndex, bool accountingBeginValid, int32_t accountBeginKindCode,	int32_t accountingBeginStatusCode, bool accountingEndValid, 
	int32_t accountingEndKindCode, int32_t accountingEndStatusCode, int32_t accountingEndItemCount, _out_ enum PlayErrorId errorId) {
	log("%d %d %d %d %d %d %d %d %p\n", playerIndex, accountingBeginValid, accountBeginKindCode, accountingBeginStatusCode,
		accountingEndValid, accountingEndKindCode, accountingEndStatusCode, accountingEndItemCount, errorId);
	in_play = false;
	return true;
}

bool Sequence_endTest() {
	log("\n");
	in_test = false;
	return true;
}

void* Sequence_getBookkeeping() {
	log("\n");
	return 0x41;
}

enum PlayAccountingTiming Sequence_getPlayAccountingTiming() {
	log("\n");
	return Normal;
}

int32_t Sequence_getPlayerCount() {
	log("\n");
	return 1;
}

uint32_t Sequence_getPlayingAimeId(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return 0;
}

bool Sequence_isAccountingPlaying(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return false;
}

bool Sequence_isPlaying(int32_t playerIndex) {
	log("%d\n", playerIndex);
	return in_play;
}

bool Sequence_isPlayingAny() {
	log("\n");
	return in_play;
}

bool Sequence_isTest() {
	log("\n");
	return in_test;
}