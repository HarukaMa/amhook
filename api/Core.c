#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum NextProcess {
	Auto,
	SegaBoot,
	SegaBootError,
	SystemTest
};

bool Core_changeLanguage(wchar_t *language) {
	log("%ls\n", language);
	return false;
}

void Core_execute() {
	log("\n");
}

wchar_t* Core_getLanguage() {
	log("\n");
	return 0;
}

wchar_t* Core_getLibraryVersion() {
	log("\n");
	return 0;
}

int32_t Core_getPlayerCount() {
	log("\n");
	return 0;
}

bool Core_isExited() {
	log("\n");
	return false;
}

bool Core_isReady() {
	log("\n");
	return true;
}

void Core_kill(enum NextProcess nextProcess) {
	log("%d\n", nextProcess);
}

void Core_reboot() {
	log("\n");
}

void Core_resetExceptionHook() {
	log("\n");
}

void Core_setExceptionHook(void (*hook)(intptr_t)) {
	log("%p\n", hook);
}
