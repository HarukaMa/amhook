#include "log.h"

enum EMoneyBrandId {
	Nanaco,
	Edy,
	Transport,
	Waon,
	Paseli
};

wchar_t* EMoneyBrand_getIconFilePath(void *brand) {
	log("%p\n", brand);
	switch ((int)brand % 0x100) {
	case 0:
		return L"O:\\ong\\package\\tfps-res-pro\\0001-01-00.png";
	case 1:
		return L"O:\\ong\\package\\tfps-res-pro\\0002-01-00.png";
	case 2:
		return L"O:\\ong\\package\\tfps-res-pro\\0005-01-00.png";
	case 3:
		return L"O:\\ong\\package\\tfps-res-pro\\0006-01-00.png";
	case 4:
		return L"O:\\ong\\package\\tfps-res-pro\\0008-01-00.png";
	}
	return 0;
}

enum EMoneyBrandId EMoneyBrand_getId(void *brand) {
	log("%p\n", brand);
	switch ((int)brand % 0x100) {
	case 0:
		return Nanaco;
	case 1:
		return Edy;
	case 2:
		return Transport;
	case 3:
		return Waon;
	case 4:
		return Paseli;
	}
	return 0;
}

wchar_t* EMoneyBrand_getName(void* brand) {
	log("%p\n", brand);
	switch ((int)brand % 0x100) {
	case 0:
		return L"nanano";
	case 1:
		return L"Šy“VEdy";
	case 2:
		return L"Œð’ÊŒn";
	case 3:
		return L"WAON";
	case 4:
		return L"PASELI";
	}
	return 0;
}