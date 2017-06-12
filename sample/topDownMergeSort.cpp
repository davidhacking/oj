#include "./stdc++.h"

using namespace std;

void mergeSort(vector<int> &t, int start, int mid, int end, vector<int> &s) {
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (t[i] <= t[j]) {
			s[k++] = t[i++];
		} else {
			s[k++] = t[j++];
		}
	}
	while (i <= mid) s[k++] = t[i++];
	while (j <= end) s[k++] = t[j++];
}

void mergeSort2(vector<int> &t, int start, int mid, int end, vector<int> &s) {
	int i = start, j = mid + 1, k = start;
	for (; i <= mid; i++, k++) {
		while (j <= end && t[i] > t[j]) s[k++] = t[j++];
		s[k] = t[i]; 
	}
	while (j <= end) s[k++] = t[j++];
}

void mergeSortSplit(vector<int> &t, int start, int end, vector<int> &s) {
	if (start >= end) return;
	int mid = start + (end - start) / 2;
	// 自身调用reverse一下，merge时又反过来
	mergeSortSplit(s, start, mid, t);
	mergeSortSplit(s, mid + 1, end, t);
	mergeSort2(t, start, mid, end, s);
}

void topDownMergeSort(vector<int> &s) {
	// you should copy tobesort array to work array first
	vector<int> t(s.begin(), s.end()); // merge sort work array
	mergeSortSplit(t, 0, s.size() - 1, s);
}

int main() {
	int a[] = {2,3,6, 1,9,10};
	vector<int> s(a, a+6); // to be sort array
	topDownMergeSort(s);
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	return 0;
}