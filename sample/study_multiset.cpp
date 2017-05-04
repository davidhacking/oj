#include "./stdc++.h"

using namespace std;

template<typename T> void print_vector(std::vector<T> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

void print_multiset(multiset<int> v) {
	for (multiset<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << ", ";
	}
	cout << endl;
}

int main() {
	multiset<int> m;
	for (int i = 0; i < 10; i++) {
		m.insert(i * 10);
	}
	print_multiset(m);
	multiset<int>::iterator i1, i2;
	i1 = m.lower_bound(31); // 在m中查找第一个大于等于参数的数
	i2 = m.upper_bound(INT_MAX); // 在m中查找第一个大于参数的数 这里bound不了参数，但是返回的是short的最大值
	cout << INT_MAX << endl;
	cout << *i1 << endl;
	cout << *i2 << endl;
	cout << *next(i1, 1) << endl; // next and prev can return the iterator that add with the params num
	cout << *prev(i2, 1) << endl;
	m.erase(*i1); // delete the iterator pointed element
	print_multiset(m);
	return 0;
}