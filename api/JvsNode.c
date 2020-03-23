#include "log.h"

void* JvsNode_getAnalogInput(void *node) {
	log("%p\n", node);
	return 0;
}

void* JvsNode_getGeneralOutput(void* node) {
	log("%p\n", node);
	return 0;
}

void* JvsNode_getRotaryInput(void* node) {
	log("%p\n", node);
	return 0;
}

void* JvsNode_getSwitchInput(void* node) {
	log("%p\n", node);
	return 0;
}
