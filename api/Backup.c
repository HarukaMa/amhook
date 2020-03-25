#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

enum BackupRecordStatus {
	Valid,
	DiffApp,
	BrokenData,
	InvalidCall = -1
};

enum BackupDevice {
	Eeprom,
	Sram,
	File
};

struct BackupRecord {
	void* Address;
	void* Size;
	enum BackupDevice Device;
};

static struct BackupRecord Records[64];

extern bool request_states_done[0x45];
extern bool request_states_sent[0x45];
extern bool request_states_succeeded[0x45];

bool Backup_executeSave() {
	log("\n");
	return false;
}

int32_t Backup_getMaxRecordCount() {
	log("\n");
	return 64;
}

int32_t Backup_getRecordCount() {
	log("\n");
	int count = 0;
	for (int i = 0; i < 64; i ++) {
		if (Records[i].Address) {
			count += 1;
		}
	}
	return count;
}

enum BackupRecordStatus Backup_getRecordStatus(int32_t recordIndex) {
	log("%d\n", recordIndex);
	char filename[13];
	sprintf(filename, "backup%d.dat", recordIndex);
	FILE* f = fopen(filename, "rb");
	if (f) {
		fclose(f);
		return Valid;
	}
	return BrokenData;
}

bool Backup_isAsync() {
	log("\n");
	return true;
}

bool Backup_isBusy() {
	log("\n");
	return false;
}

bool Backup_isSetupSucceeded() {
	log("\n");
	return true;
}

void* Backup_saveAllRecords() {
	log("\n");
	for (int i = 0; i < 64; i ++) {
		if (Records[i].Address) {
			char filename[13];
			sprintf(filename, "backup%d.dat", i);
			FILE* f = fopen(filename, "wb");
			if (f) {
				fwrite(Records[i].Address, Records[i].Size, 1, f);
				fclose(f);
			}
		}
	}
	return 0x15;
}

DWORD WINAPI Backup_saveRecord_worker(int *index) {
	Sleep(100);
	if (Records[*index].Address) {
		char filename[13];
		sprintf(filename, "backup%d.dat", *index);
		FILE* f = fopen(filename, "wb");
		if (f) {
			fwrite(Records[*index].Address, Records[*index].Size, 1, f);
			fclose(f);
			request_states_succeeded[0x16] = true;
		}
	}
	free(index);
	request_states_done[0x16] = true;
	return 0;
}

void* Backup_saveRecord(int32_t recordIndex) {
	log("%d\n", recordIndex);
	int* index = (int*)malloc(sizeof(int));
	*index = recordIndex;
	CreateThread(NULL, 0, &Backup_saveRecord_worker, index, 0, NULL);
	request_states_sent[0x16] = true;
	return 0x16;
}

void Backup_setAsync(bool async) {
	log("%d\n", async);	
}

void* Backup_setupRecords(struct BackupRecord *records, int32_t count, wchar_t *gameId) {
	log("%p %d %ls\n", records, count, gameId);
	for (int i = 0; i < count; i ++) {
		struct BackupRecord record = records[i];
		Records[i].Size = record.Size;
		Records[i].Address = record.Address;
		Records[i].Device = record.Device;
		char filename[13];
		sprintf(filename, "backup%d.dat", i);
		FILE* f = fopen(filename, "rb");
		if (f) {
			void* buf = malloc(record.Size);
			fread(buf, record.Size, 1, f);
			memcpy(record.Address, buf, record.Size);
			fclose(f);
			free(buf);
		}
	}
	request_states_sent[0x17] = true;
	request_states_done[0x17] = true;
	request_states_succeeded[0x17] = true;
	return 0x17;
}

