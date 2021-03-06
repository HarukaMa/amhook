#include <stdint.h>

#include "log.h"

uint32_t total_time = 0;

extern void save_bookkeeping_data();

DWORD WINAPI count_total_time(void * _) {
	while (1) {
		Sleep(1000);
		total_time += 1;
		if (total_time % 60 == 0) {
			save_bookkeeping_data();
		}
	}
	return 0;
}

int32_t SequenceBookkeeping_MaxTimeHistogramCount_get() {
	log("\n");
	return 0;
}

uint32_t SequenceBookkeeping_averagePlayTime_get(void *bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t SequenceBookkeeping_longestPlayTime_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t SequenceBookkeeping_numberOfGames_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t SequenceBookkeeping_playTime_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

uint32_t SequenceBookkeeping_shortestPlayTime_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

int32_t SequenceBookkeeping_timeHistogramCount_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0;
}

void* SequenceBookkeeping_timeHistogram_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return 0x42;
}

uint32_t SequenceBookkeeping_totalTime_get(void* bookkeeping) {
	log("%p\n", bookkeeping);
	return total_time;
}
