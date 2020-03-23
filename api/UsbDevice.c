#include <stdbool.h>
#include <stdint.h>


#include "log.h"

enum UsbDeviceReconnectResult {
	None,
	Success,
	Error,
	NotFound
};

enum UsbDeviceReconnectResult UsbDevice_getLastReconnectResult() {
	log("\n");
	return None;
}

bool UsbDevice_isReconnectBusy() {
	log("\n");
	return false;
}

bool UsbDevice_startReconnect(uint16_t vendorId, uint16_t productId) {
	log("%d %d\n", vendorId, productId);
	return false;
}

