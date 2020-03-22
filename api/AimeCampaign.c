#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t AimeCampaignCountLimit_get() {
	log("\n");
	return 3;
}

int32_t AimeCampaignInfo_MaxNameLength_get() {
	log("\n");
	return 127;
}

uint32_t AimeCampaignInfo_id_get(void *info) {
	log("%p\n", info);
	return *(uint32_t *)info;
}

wchar_t* AimeCampaignInfo_name_get(void* info) {
	log("%p\n", info);
	return (wchar_t *)((char *)info + 4);
}

uint64_t AimeCampaignInfo_noticeTime_get(void* info) {
	log("%p\n", info);
	return 0;
}

uint64_t AimeCampaignInfo_openTimeRange_begin_get(void* info) {
	log("%p\n", info);
	return 0;
}

uint64_t AimeCampaignInfo_openTimeRange_end_get(void* info) {
	log("%p\n", info);
	return 0;
}

uint64_t AimeCampaignInfo_rewardTimeRange_begin_get(void* info) {
	log("%p\n", info);
	return 0;
}

uint64_t AimeCampaignInfo_rewardTimeRange_end_get(void* info) {
	log("%p\n", info);
	return 0;
}

uint32_t AimeCampaignProgress_bits_get(void *progress) {
	log("%p\n", progress);
	return 0;
}

bool AimeCampaignProgress_entry_get(void* progress) {
	log("%p\n", progress);
	return false;
}

uint32_t AimeCampaignProgress_id_get(void* progress) {
	log("%p\n", progress);
	return 0;
}