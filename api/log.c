#include "log.h"

FILE* output = NULL;

void log_(const char* format, ...) {
#if 0
	if (!output) {
		output = fopen("amdaemon.log", "w");
	}
	va_list args;
	va_start(args, format);
	SYSTEMTIME st;
	GetSystemTime(&st);
	char new_format[64];
	sprintf(new_format, "%%s %s", format);
	char buffer[256];
	vsprintf(buffer, new_format, args);
	char result[512];
	sprintf(result, "[%04d-%02d-%02d %02d:%02d:%02d.%03d] %s", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, buffer);
	OutputDebugStringA(result);
	fprintf(output, "%s", result);
	fflush(output);
#endif
}