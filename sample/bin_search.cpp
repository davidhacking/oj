#include "./stdc++.h"

using namespace std;

int bin_search(vector<int> &v, int fromIndex, int toIndex, int key) {
	if (v.size() <= 0) {
		return -1;
	}

	int low = fromIndex;
    int high = toIndex;

    while (low <= high) {
        int mid = (low + high) >> 1;
        int midVal = v[mid];

        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return mid; // key found
    }
    return -(low + 1);  // key not found.
}

void print_v(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

void print_vi(vector<int> &v) {
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << ", ";
	}
	cout << endl;
}

int main() {
	int a[] = {1,2,3,4,5,6,8,9};
	vector<int> v(a, a + 8);
	print_vi(v);
	int b = bin_search(v, 0, 7, -1);
	cout << b << endl; // -1
	b = -(b + 1);
	cout << b << endl; // 0

	b = bin_search(v, 0, 7, 7);
	cout << b << endl; // -7
	b = -(b + 1);
	cout << b << endl; // 6
	v.insert(v.begin() + 6, 7);
	print_vi(v);
	return 0;
}