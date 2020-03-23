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
	return 0;
}

enum EMoneyBrandId EMoneyBrand_getId(void *brand) {
	log("%p\n", brand);
	return Transport;
}

wchar_t* EMoneyBrand_getName(void* brand) {
	log("%p\n", brand);
	return 0;
}