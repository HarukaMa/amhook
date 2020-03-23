#include "log.h"

enum TestResult {
	None,
	NA,
	Good,
	Bad
};

wchar_t* TestResult_toString(enum TestResult result) {
	log("%d\n", result);
	return None;
}
