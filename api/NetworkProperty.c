#include <stdbool.h>

#include "log.h"

void NetworkProperty_getAddress(void *property, void (*func)(wchar_t*)) {
	log("%p %p\n", property, func);
	func(L"127.0.0.1");
}

void NetworkProperty_getGateway(void* property, void (*func)(intptr_t)) {
	log("%p %p\n", property, func);
}

void NetworkProperty_getPrimaryDns(void* property, void (*func)(intptr_t)) {
	log("%p %p\n", property, func);
}

void NetworkProperty_getSecondaryDns(void* property, void (*func)(intptr_t)) {
	log("%p %p\n", property, func);
}

void NetworkProperty_getSubnetMask(void* property, void (*func)(wchar_t*)) {
	log("%p %p\n", property, func);
	func(L"255.255.255.255");
}

bool NetworkProperty_isDhcpEnabled(void *property) {
	log("%p\n", property);
	return false;
}

bool NetworkProperty_valid(void* property) {
	log("%p\n", property);
	return false;
}
