#include <stdbool.h>

#include "log.h"

static wchar_t* NetDeliveryStatusString_jp[8] = {
		L"�s��",
		L"�G���[",
		L"�_�E�����[�h�J�n�O",
		L"�_�E�����[�h��",
		L"�_�E�����[�h����",
		L"���J�\",
		L"���J�ς�",
		L"���g���C"
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
