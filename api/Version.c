#include <stdbool.h>
#include <stdint.h>

#include "log.h"

uint32_t Version_MajorLimit_get() {
	log("\n");
	return 0xFFFF;
}

uint32_t Version_MinorLimit_get() {
	log("\n");
	return 255;
}

uint32_t Version_PatchLimit_get() {
	log("\n");
	return 255;
}

bool Version_canMake_fromParts(uint32_t major, uint32_t minor, uint32_t patch) {
	log("%d %d %d\n", major, minor, patch);
	return false;
}

bool Version_canMake_fromString(wchar_t *src) {
	log("%ls", src);
	return false;
}

uint32_t Version_major(uint32_t value) {
	log("%d\n", value);
	return value >> 16;
}

uint32_t Version_make_fromParts(uint32_t major, uint32_t minor, uint32_t patch) {
	log("%d %d %d\n", major, minor, patch);
	return 0;
}

uint32_t Version_make_fromString(wchar_t* src) {
	log("%ls", src);
	return 0;
}

uint32_t Version_minor(uint32_t value) {
	log("%d\n", value);
	return (value >> 8) & 0xff;
}

uint32_t Version_patch(uint32_t value) {
	log("%d\n", value);
	return value & 0xff;
}

void Version_toString(uint32_t value, bool withoutPatch, void (*func)(intptr_t)) {
	log("%d %d %p\n", value, withoutPatch, func);
}