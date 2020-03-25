#include <stdio.h>

#include "log.h"

enum AimeErrorCategory {
	None,
	Warning,
	Network,
	Fatal,
	Unknown
};

enum AimeErrorId {
	ErrorNone,
	ReaderSetupFail,
	ReaderFirmFileInvalid,
	ReaderFirmUpToDate,
	ReaderAccessFail,
	ReaderTimeout,
	ReaderIncompatible,
	ReaderTwoOrMore,
	DBResolveFail,
	DBAccessTimeout,
	DBAccessFail,
	FeliCaInvalid,
	FeliCaNotFound,
	FeliCaRegisterFail,
	AimeIdInvalid,
	AimeIdNotFound,
	AimeIdRegisterFail,
	FeliCaRequired,
	CardRequired,
	NoBoardInfo,
	LogRegisterFail,
	FeliCaRegistered,
	AimeIdRegistered,
	LockBanSystemUser,
	LockBanSystem,
	LockBanUser,
	LockBan,
	LockSystemUser,
	LockSystem,
	LockUser,
	ReaderFirmUpdateFail,
	CampaignInfoFail,
	ReaderDetectFail,
	FeliCaComFail
};

enum AimeErrorCategory aime_error_category;
enum AimeErrorId aime_error_id;

void* AimeErrorInfo_base(void *info) {
	log("%p\n", info);
	return 0x7;
}

enum AimeErrorCategory AimeErrorInfo_getCategory(void *info) {
	log("%p\n", info);
	return Fatal;
}

enum AimeErrorId AimeErrorInfo_getId(void *info) {
	log("%p\n", info);
	return aime_error_id;
}

