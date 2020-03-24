#include <stdbool.h>

#include "log.h"

bool RequestState_isDone(void* state) {
	log("%p\n", state);
	return true;
}

bool RequestState_isSent(void* state) {
	log("%p\n", state);
	return true;
}

bool RequestState_isSucceeded(void* state) {
	log("%p\n", state);
	return true;
}
