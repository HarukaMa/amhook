#include <stdbool.h>

#include "log.h"

void NetworkProperty_getAddress(void *property, void (*func)(intptr_t)) {
	log("%p %p\n", property, func);
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

void NetworkProperty_getSubnetMask(void* property, void (*func)(intptr_t)) {
	log("%p %p\n", property, func);
}

bool NetworkProperty_isDhcpEnabled(void *property) {
	log("%p\n", property);
	return false;
}

bool NetworkProperty_valid(void* property) {
	log("%p\n", property);
	return false;
}
