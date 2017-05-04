#include "./stdc++.h"

using namespace std;

/*
优先队列是用heap实现的
当你调用push_back是底层使用push_heap来整理数据reorder
*/

struct Data {
	int x;
	Data(int x): x(x) {}
};

struct MyComp{
	bool operator() (Data a, Data b) {
		return a.x > b.x;
	}
};

struct MyComp2{
	bool operator() (int a, int b) {
		return a > b;
	}
} comp2;

bool func_comp(int a, int b) {
	return a > b;
}

void print_pq(priority_queue<int> v) {
	while (!v.empty()) {
		cout << v.top() << ", ";
		v.pop();
	}
	cout << endl;
}

template<typename T> void print_pq2(priority_queue<T, std::vector<T>, greater<T> > v) {
	while (!v.empty()) {
		cout << v.top() << ", ";
		v.pop();
	}
	cout << endl;
}

void print_pq3(priority_queue<Data, std::vector<Data>, MyComp > v) {
	while (!v.empty()) {
		cout << v.top().x << ", ";
		v.pop();
	}
	cout << endl;
}

void print_v(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	// priority_queue<int> pq; // 大顶堆
	priority_queue<int, std::vector<int>, greater<int> > pq; // 小顶堆
	for (int i = 0; i < 10; i++)
		pq.push(i * 10);
	// print_pq(pq);
	print_pq2(pq);

	priority_queue<Data, std::vector<Data>, MyComp > pq2;
	for (int i = 0; i < 10; i++)
		pq2.push(Data(i * 10));
	print_pq3(pq2);

	int a[] = {-1, 0, 1, 2, -1, -4};
	std::vector<int> v(a, a + 6);
	sort(v.begin(), v.end()); // 升序
	print_v(v);
	sort(v.begin(), v.end(), comp2); // object 降序
	print_v(v);
	sort(v.begin(), v.end());
	print_v(v);
	sort(v.begin(), v.end(), func_comp);
	print_v(v);

	return 0;
}