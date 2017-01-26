#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

bool is_prime(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	while (true) {
		int input = 0;
		scanf("%d", &input);
		if (input == 0 || input > 1e6 || input < 6) {
			return 0;
		}
		int end = (input + 1) / 2;
		bool flag = false;
		for (int i = 2; i <= end; i++) {
			if (flag) {
				break;
			}
			if (is_prime(i)) {
				int j = input - i;
				if (is_prime(j)) {
					cout << input << " = " << i << " + " << j << endl;
					flag = true;
				}
			}
		}
		if (flag == false) {
			cout << "Goldbach's conjecture is wrong.\n";
			return 0;
		}
	}
	return 0;
}