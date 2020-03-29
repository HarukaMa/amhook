#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum LineType {
	Unknown,
	Broadband,
	Mobile,
	Xdsl
};

enum Prefecture {
	None,
	Aichi,
	Aomori,
	Akita,
	Ishikawa,
	Ibaraki,
	Iwate,
	Ehime,
	Oita,
	Osaka,
	Okayama,
	Okinawa,
	Kagawa,
	Kagoshima,
	Kanagawa,
	Gifu,
	Kyoto,
	Kumamoto,
	Gunma,
	Kouchi,
	Saitama,
	Saga,
	Shiga,
	Shizuoka,
	Shimane,
	Chiba,
	Tokyo,
	Tokushima,
	Tochigi,
	Tottori,
	Toyama,
	Nagasaki,
	Nagano,
	Nara,
	Niigata,
	Hyogo,
	Hiroshima,
	Fukui,
	Fukuoka,
	Fukushima,
	Hokkaido,
	Mie,
	Miyagi,
	Miyazaki,
	Yamagata,
	Yamaguchi,
	Yamanashi,
	Wakayama,
	Max
};

wchar_t* allnet_Auth_getCountryCode() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getGameServerHost() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getGameServerUri() {
	log("\n");
	return L"http://raw.mrx.im:10500/";
}

enum LineType allnet_Auth_getLineType() {
	log("\n");
	return Unknown;
}

uint32_t allnet_Auth_getLocationId() {
	log("\n");
	return 0;
}

wchar_t* allnet_Auth_getLocationName() {
	log("\n");
	return L"Location";
}

wchar_t* allnet_Auth_getLocationNickname(int32_t partIndex) {
	log("%d\n", partIndex);
	return L"Loc";
}

int32_t allnet_Auth_getLocationNicknamePartCount() {
	log("\n");
	return 1;
}

int32_t allnet_Auth_getRegionCode() {
	log("\n");
	return Tokyo;
}

wchar_t* allnet_Auth_getRegionName(int32_t partIndex) {
	log("%d\n", partIndex);
	return L"Tokyo";
}

int32_t allnet_Auth_getRegionNamePartCount() {
	log("\n");
	return 1;
}

bool allnet_Auth_isAvailable() {
	log("\n");
	return true;
}

bool allnet_Auth_isDevelop() {
	log("\n");
	return false;
}

bool allnet_Auth_isGood() {
	log("\n");
	return true;
}
