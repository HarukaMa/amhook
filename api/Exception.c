
#include <stdbool.h>
#include <stdint.h>

#include "log.h"

enum ExceptionCategory {
	Logic,
	Operation,
	Runtime,
	Fatal,
	Unknown
};

enum ExceptionCategory Exception_getCategory(void *ex) {
	log("%p\n", ex);
	return Unknown;
}

wchar_t* Exception_getFile(void* ex) {
	log("%p\n", ex);
	return 0;
}

wchar_t* Exception_getFunction(void* ex) {
	log("%p\n", ex);
	return 0;
}

int32_t Exception_getLine(void* ex) {
	log("%p\n", ex);
	return 0;
}

wchar_t* Exception_getMessage(void* ex) {
	log("%p\n", ex);
	return 0;
}

wchar_t* Exception_getStackTrace(void* ex) {
	log("%p\n", ex);
	return 0;
}

wchar_t* Exception_toString(void *ex, bool withoutStacktrace) {
	log("%p %d\n", ex, withoutStacktrace);
	return 0;
}
