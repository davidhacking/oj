#include <stdio.h>
#include "dump.h"

int main() {
	float f1 = 1.0;
	float f2 = -1.0;
	float f3 = 3.14;
	float f4 = -3.14;
	double d1 = 1.0;
	double d2 = -1.0;
	double d3 = 3.14;
	double d4 = -3.14;
	dump_data((const char *) &f1, 4, "f1");
	dump_data((const char *) &f2, 4, "f2");
	return 0;
}