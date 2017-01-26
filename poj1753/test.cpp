#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

static void toggle(char *c) {
	if (*c == 'w') {
		*c = 'b';
	} else if (*c == 'b') {
		*c = 'w';
	} else {
		cout << "error" << endl;
	}
}

static void print_r(char rectangular_tmp[][]) {
	cout << "rectangular_tmp: " << endl;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			cout << rectangular_tmp[x][y] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	bool slot[16] = {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0,};
	char rectangular_tmp[][] = { {'b', 'w','w', 'b'},
								 {'b', 'b', 'w', 'b'},
								 {'b', 'w', 'w', 'b'},
								 {'b', 'w', 'w', 'w'} };
	for (int i = 0; i < 16; i++) {
		if (slot[i]) {
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					int tmp = x * 4 + y;
					if (tmp == i) {
						toggle(&(rectangular_tmp[x][y]));
						if (x != 0) {
							toggle(&(rectangular_tmp[x - 1][y]));
						}
						if (y != 3) {
							toggle(&(rectangular_tmp[x][y + 1]));
						}
						if (x != 3) {
							toggle(&(rectangular_tmp[x + 1][y]));
						}
						if (y != 0) {
							toggle(&(rectangular_tmp[x][y - 1]));
						}
						// cout << "i: " << i << endl;
						// print_r();
					}
				}
			}
		}
	}
	print_r(rectangular_tmp);
}