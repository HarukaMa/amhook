#include "log.h"

void* JvsNode_getAnalogInput(void *node) {
	log("%p\n", node);
	return 0x30;
}

void* JvsNode_getGeneralOutput(void* node) {
	log("%p\n", node);
	return 0x31;
}

void* JvsNode_getRotaryInput(void* node) {
	log("%p\n", node);
	return 0x32;
}

void* JvsNode_getSwitchInput(void* node) {
	log("%p\n", node);
	return 0x33;
}
