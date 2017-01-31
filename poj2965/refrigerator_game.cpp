#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


class Combination {
	private: 
		bool *slot;
		int n;
		int m;
		int count;
		void (*on_result) (bool *, int);

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
				this->on_result(this->slot, this->n);
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

		void compute(void (*func) (bool *, int)) {
			this->on_result = func;
			c_n_m(this->n, this->m, this->slot);
			this->on_result = NULL;
		}

		void print_slot_call_count() {
			cout << "print_slot_call_count: " << count << endl;
		}
};


static void on_compute_result(bool *slot, int slot_len) {
	for (int i = 0; i < slot_len; i++) {
		if (slot[i]) {
			cout << i << ", ";
		}
	}
	cout << endl;
}

int main() {
	Combination c = Combination(6, 2);
	c.compute(on_compute_result);
	c.print_slot_call_count();
	return 0;
}