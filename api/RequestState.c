#include <stdbool.h>

#include "log.h"

bool request_states_done[0x45] = { false };
bool request_states_sent[0x45] = { false };
bool request_states_succeeded[0x45] = { false };

bool RequestState_isDone(void* state) {
	log("%p\n", state);
	if (request_states_done[(int)state]) {
		request_states_done[(int)state] = false;
		return true;
	}
	return false;
}

bool RequestState_isSent(void* state) {
	log("%p\n", state);
	if (request_states_sent[(int)state]) {
		request_states_sent[(int)state] = false;
		return true;
	}
	return false;
}

bool RequestState_isSucceeded(void* state) {
	log("%p\n", state);
	if (request_states_succeeded[(int)state]) {
		request_states_succeeded[(int)state] = false;
		return true;
	}
	return false;
}
