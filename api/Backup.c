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

bool Backup_executeSave() {
	log("\n");
	return 0;
}

int32_t Backup_getMaxRecordCount() {
	log("\n");
	return 0;
}

int32_t Backup_getRecordCount() {
	log("\n");
	return 0;
}

enum BackupRecordStatus Backup_getRecordStatus(int32_t recordIndex) {
	log("%d\n", recordIndex);
	return InvalidCall;
}

bool Backup_isAsync() {
	log("\n");
	return false;
}

bool Backup_isBusy() {
	log("\n");
	return false;
}

bool Backup_isSetupSucceeded() {
	log("\n");
	return false;
}

void* Backup_saveAllRecords() {
	log("\n");
	return 0;
}

void* Backup_saveRecord(int32_t recordIndex) {
	log("%d\n", recordIndex);
	return 0;
}

void Backup_setAsync(bool async) {
	log("%d\n", async);	
}

void* Backup_setupRecords(void *records, int32_t count, wchar_t *gameId) {
	log("%p %d %ls\n", records, count, gameId);
	return 0;
}

