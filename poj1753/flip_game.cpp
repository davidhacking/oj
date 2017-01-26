#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char rectangular[4][4];
char rectangular_tmp[4][4];

static void toggle(char *c) {
	if (*c == 'w') {
		*c = 'b';
	} else if (*c == 'b') {
		*c = 'w';
	}
}

static void copy_rectangular(char *r) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			*(r + (x * 4) + y) = rectangular[x][y];
		}
	}
}

static void print_s(bool *slot) {
	cout << "slot: " << endl;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			cout << slot[x * 4 + y] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

static void print_r() {
	cout << "rectangular_tmp: " << endl;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			cout << rectangular_tmp[x][y] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

static void print_r2() {
	cout << "rectangular: " << endl;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			cout << rectangular[x][y] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

static bool is_all_same(char *r) {
	char tmp = r[0];
	for (int i = 1; i < 16; i++) {
		if (tmp != r[i]) {
			return false;
		}
	}
	return true;
}

static void on_compute_result(bool *slot, int slot_len, int m) {
	copy_rectangular(rectangular_tmp[0]);
	for (int i = 0; i < slot_len; i++) {
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
	// if (slot[2] & slot[]) {
	// 	print_s(slot);
	// 	print_r();
	// }
	if (is_all_same(rectangular_tmp[0])) {
		// print_s(slot);
		// print_r2();
		// print_r();
		cout << m << endl;
		exit(0);
	}
}

class Combination {
	private: 
		bool *slot;
		int n;
		int m;
		int count;
		void (*on_result) (bool *, int, int);

	public:
		Combination(int n, int m) {
			slot = (bool *) malloc(n * sizeof(bool));
			memset(slot, 0, n * sizeof(bool));
			this->n = n;
			this->m = m;
			this->count = 0;
		}
		~Combination() {
			free(slot);
		}

	protected:
		void print_slot() {
			if (this->on_result != NULL) {
				this->on_result(this->slot, this->n, this->m);
			}
			this->count++;
		}


		void c_n_m(int n, int m, bool *slot) {
			for (int i = 0; i < n; i++) {
				slot[i] = true;
				if (m == 1) {
					print_slot();
				}
				if (m > 1 && m - 1 <= n - i - 1) {
					c_n_m(n - i - 1, m - 1, slot + i + 1);
				}
				slot[i] = false;
			}
		}

	public:
		void compute() {
			c_n_m(this->n, this->m, this->slot);
		}

		void compute(void (*func) (bool *, int, int)) {
			this->on_result = func;
			c_n_m(this->n, this->m, this->slot);
			this->on_result = NULL;
		}

		void print_slot_call_count() {
			cout << "print_slot_call_count: " << count << endl;
		}
};

/*
bwwb
bbwb
bwwb
bwww


*/

int main() {

	// freopen("/Users/david/myFile/OJ/poj1753/test.data", "r", stdin);
	scanf("%s", rectangular[0]);
	scanf("%s", rectangular[1]);
	scanf("%s", rectangular[2]);
	scanf("%s", rectangular[3]);

	if (is_all_same(rectangular[0])) {
		cout << "0" << endl;
		exit(0);
	}

	for (int i = 1; i <= 16; i++) {
		Combination c = Combination(16, i);
		copy_rectangular(rectangular_tmp[0]);
		c.compute(on_compute_result);
	}
	cout << "Impossible" << endl;
	return 0;
}