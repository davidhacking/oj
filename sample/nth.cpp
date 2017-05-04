#include <bits/stdc++.h>
#include <stdlib.h>

#define random(x) (rand() % x)

using namespace std;

void swap(int &a, int &b) {
	if (a == b)
		return;
	a ^= b;
	b ^= a;
	a ^= b;
	/*int t = a;
	a = b;
	b = t;*/
}

/*
�����һ����Ϊ��׼��retָ����ʹ�õ�С�ڻ�׼�ĵ�Ԫ���жϵ�ǰ�����׼�Ĵ�С��ϵ��
��С�ڻ�׼�򽻻�retָ���ǰһ����Ԫ�����retָ���ǰһ����Ԫ���׼����������
��׼֮ǰ�ĵ�Ԫһ���Ȼ�׼С
���Ҫ��ĳ���ڼ�С������ʹ�õݹ���ң�ʹ��ĳһ�λ�׼���ڵ�λ��ǡ���Ǵ��鵥Ԫ
*/

int partition(vector<int> &a, int l, int r) {
	int ret = l - 1;
	for (int i = l; i < r; i++) {
		if (a[i] < a[r]) {
			swap(a[i], a[++ret]);
			// cout << "swap: " << i << ", " << ret << endl;
		}
	}
	swap(a[++ret], a[r]);
	return ret;
}

void print_v(vector<int> &a) {
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

int nth(vector<int> &a, int s, int e, int i) {
	int mid = partition(a, s, e);
	cout << "mid: " << mid << endl;
	print_v(a);
	if (mid == i)
		return a[mid];
	return (mid < i) ? nth(a, mid + 1, e, i) : nth(a, s, mid - 1, i);
}

int main() {
	vector<int> v;
	int size = 20;
	for (int i = 0; i < size; i++)
	{
		v.push_back(random(100));
	}
	int x = 12;
	print_v(v);
	/*cout << x << "th: " << nth(v, 0, size - 1, x - 1) << endl;
	print_v(v);
	nth_element(v.begin(), v.begin() + 10, v.end());
	print_v(v);
	cout << *(v.begin() + 11) << endl;*/
	cout << partition(v, 0, size - 1) << endl;
	print_v(v);
	return 0;
}