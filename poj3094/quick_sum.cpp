#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

/*
ACM
MID CENTRAL
REGIONAL PROGRAMMING CONTEST
ACN
A C M
ABC
BBC
#


*/

int main() {
	char input[256];
	memset(input, 0, 256);
	while (true) {
		cin.getline(input, 256);
		if (strcmp(input, "#") == 0) {
			return 0;
		}
		long quick_sum = 0;
		for (int i = 0; i < strlen(input); i++) {
			int tmp = 0;
			if (input[i] <= 'Z' && input[i] >= 'A') {
				tmp = input[i] - 'A' + 1;
			}
			tmp *= i + 1;
			quick_sum += tmp;
		}
		cout << quick_sum << endl;
		memset(input, 0, 256);
	}
	return 0;
}