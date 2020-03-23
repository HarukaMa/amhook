#include <stdbool.h>

#include "log.h"

static wchar_t* NetDeliveryStatusString_jp[8] = {
		L"不明",
		L"エラー",
		L"ダウンロード開始前",
		L"ダウンロード中",
		L"ダウンロード完了",
		L"公開可能",
		L"公開済み",
		L"リトライ"
};

static wchar_t* NetDeliveryStatusString_en[8] = {
		L"UNKNOWN",
		L"ERROR",
		L"NOT START",
		L"DOWNLOAD",
		L"COMPLETE",
		L"UPDATE READY",
		L"UP TO DATE",
		L"RETRY"
};

wchar_t* NetDeliveryStatus_toString(enum NetDeliveryStatus status, bool japanese) {
	log("%d %d\n", status, japanese);
	if (status < 0 || status >= 8) {
		return 0;
	}
	if (japanese) {
		return NetDeliveryStatusString_jp[status];
	}
	return NetDeliveryStatusString_en[status];
}
