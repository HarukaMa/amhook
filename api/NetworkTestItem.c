#include "log.h"

static wchar_t* NetworkTestItemString[9] = {
	L"IP ADDRESS",
	L"GATEWAY",
	L"DNS(LAN)",
	L"HOPS",
	L"LINE TYPE",
	L"ALL.Net AUTHENTICATION",
	L"Aime",
	L"E-Money",
	L"AimePay"
};

wchar_t* NetworkTestItem_toString(enum NetworkTestItem item) {
	log("%d\n", item);
	if (item > 8) {
		return 0;
	}
	return NetworkTestItemString[item];
}
