#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

enum ApmGameExitReason {
	None,
	Unknown,
	System,
	GameTest,
	Game,
	SubSystemTest
};

bool Apm_exitGame(bool test) {
	log("%d\n", test);
	return 0;
}

enum ApmGameExitReason Apm_getLastGameExitReason() {
	log("\n");
	return Unknown;
}

bool Apm_startGame(uint32_t appVersionValue, wchar_t *gameId, bool withAime) {
	log("%d %ls %d\n", appVersionValue, gameId, withAime);
	return false;
}

