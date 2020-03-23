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

bool Sequence_beginPlay(int32_t playerIndex, int32_t gameCostIndex, int32_t gameCostCount, bool accountingBeginValid, int32_t accountBeginKindCode,
	int32_t accountingBeginStatusCode, bool accountingEndValid, int32_t accountingEndKindCode, int32_t accountingEndStatusCode, int32_t accountingEndItemCount,
	uint32_t aimeId, _out_ enum PlayErrorId errorId) {
	log("%d %d %d %d %d %d %d %d %d %d %d %p", playerIndex, gameCostIndex, gameCostCount, accountingBeginValid, accountBeginKindCode, accountingBeginStatusCode,
		accountingEndValid, accountingEndKindCode, accountingEndStatusCode, accountingEndItemCount, aimeId, errorId);
	return false;
}

bool Sequence_beginTest() {
	log("\n");
	return false;
}

bool Sequence_clearBackup() {
	log("\n");
	return false;
}

bool Sequence_continuePlay(int32_t playerIndex, int32_t gameCostIndex, int32_t gameCostCount, bool accountingBeginValid, int32_t accountBeginKindCode,
	int32_t accountingBeginStatusCode, bool accountingEndValid, int32_t accountingEndKindCode, int32_t accountingEndStatusCode, int32_t accountingEndItemCount,
	_out_ enum PlayErrorId errorId) {
	log("%d %d %d %d %d %d %d %d %d %d %p", playerIndex, gameCostIndex, gameCostCount, accountingBeginValid, accountBeginKindCode, accountingBeginStatusCode,
		accountingEndValid, accountingEndKindCode, accountingEndStatusCode, accountingEndItemCount, errorId);
	return false;
}

bool Sequence_endPlay(int32_t playerIndex, bool accountingBeginValid, int32_t accountBeginKindCode,	int32_t accountingBeginStatusCode, bool accountingEndValid, 
	int32_t accountingEndKindCode, int32_t accountingEndStatusCode, int32_t accountingEndItemCount, _out_ enum PlayErrorId errorId) {
	log("%d %d %d %d %d %d %d %d %p", playerIndex, accountingBeginValid, accountBeginKindCode, accountingBeginStatusCode,
		accountingEndValid, accountingEndKindCode, accountingEndStatusCode, accountingEndItemCount, errorId);
	return false;
}

bool Sequence_endTest() {
	log("\n");
	return false;
}

void* Sequence_getBookkeeping() {
	log("\n");
	return 0;
}

enum PlayAccountingTiming Sequence_getPlayAccountingTiming() {
	log("\n");
	return Normal;
}

int32_t Sequence_getPlayerCount() {
	log("\n");
	return 0;
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
	return false;
}

bool Sequence_isPlayingAny() {
	log("\n");
	return false;
}

bool Sequence_isTest() {
	log("\n");
	return false;
}