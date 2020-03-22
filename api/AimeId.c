#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint32_t AimeId_makeInvalid() {
	log("\n");
	return 0;
}

bool AimeId_valid(uint32_t id) {
	log("%d\n", id);
	return false;
}
