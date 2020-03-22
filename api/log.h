#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#define log(format, ...)\
	log_(format, __func__, ##__VA_ARGS__)

void log_(const char* format, ...);