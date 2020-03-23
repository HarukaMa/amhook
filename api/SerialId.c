#include <stdbool.h>

#include "log.h"

bool SerialId_empty(void *serialId) {
	log("%p\n", serialId);
	return false;
}

wchar_t* SerialId_id_value(void* serialId) {
	log("%p\n", serialId);
	return 0;
}

bool SerialId_operator_equals(void *serialIdL, void *serialIdR) {
	log("%p %p\n", serialIdL, serialIdR);
	return 0;
}

wchar_t* SerialId_shortId_value(void* serialId) {
	log("%p\n", serialId);
	return 0;
}

wchar_t* SerialId_toString(void *serialId, bool useShort) {
	log("%p %d\n", serialId, useShort);
	return 0;
}