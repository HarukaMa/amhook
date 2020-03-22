#include <stdio.h>

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

void* AimeErrorInfo_base(void *info) {
	log("%p\n", info);
	return info;
}

enum AimeErrorCategory AimeErrorInfo_getCategory(void *info) {
	log("%p\n", info);
	return Unknown;
}

enum AimeErrorId AimeErrorInfo_getId(void *info) {
	log("%p\n", info);
	return ReaderIncompatible;
}

