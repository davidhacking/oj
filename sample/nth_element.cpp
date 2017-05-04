#include "./stdc++.h"

using namespace std;

void print_v(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	int a[] = {4,5,2,34,90,3,5};
	std::vector<int> v(a, a + 7);
	print_v(v);
	nth_element(v.begin(), v.begin() + 2, v.end());
	print_v(v);
	cout << "The median is " << v[2] << endl;
	return 0;
}