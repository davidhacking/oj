//#include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;

void print_vector(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

bool comp(int a, int b) {
	return a > b;
}


int main() {
	// stack 默认初始化
	stack<int> s1;
	stack<int> s4;
	stack<string> s5;
	// stack 构造函数可以使用现有的vector进行初始化
	vector<int> v(2, 100);
	stack<int, vector<int> > s2(v);
	// 规定stack的底层数据结构实现方式
	stack<int, list<int> >   s3;
	// stack.empty的使用方法 bool empty() const
	while (!s1.empty()) {

	}
	s1.push(1);
	int tmp = s1.top(); s1.pop();
	s1.size();
	// stack swap: void swap(stack& x) 用于将两个栈交换
	//s1.swap(s4);
	// stack emplace template <class... Args> void emplace(Args&&... args); 总是将元素放到最顶 测试失败
	s5.push("3");
	s5.push("4");
	string tmp2 = s5.top(); s5.pop(); // 4
	string tmp3 = s5.top(); s5.pop(); // 3
	cout << tmp2 << " " << tmp3 << endl;

	// 一般地stack元素读取
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	while (!s1.empty()) {
		cout << s1.top() << endl;
		s1.pop();
	}

	// queue 单向队列，不能随机访问
	/*
	主要的使用方法：
		empty
		front
		back
		push
		pop
		emplace 这个是将元素插入到队列的尾部 测试失败
		swap 交换两个队列
	*/
	cout << "queue test " << endl;
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty()) {
		cout << q.front() << ", " << q.back() << endl;
		q.pop();
	}
	cout << endl;

	// deque 双向队列，有迭代器，可以随机访问

	// vector 初始化
	vector<int> v0;
	vector<int> v1(10);
	vector<int> v2(10, 0); // init 10 element with value 0
	vector<int> v3(v2);
	vector<int> v4(v3.begin(), v3.begin() + 3); // init v4 with v3 0, 1, 2
	// init with array
	int a[] = {1, 2, 3, 4, 5};
	vector<int> v5(a, a+5);
	vector<int> v6(a + 1, a + 4);
	vector<int> v7(&a[1], &a[4]);
	print_vector(v5); // 1, 2, 3, 4, 5,
	print_vector(v6); // 2, 3, 4,
	print_vector(v7); // 2, 3, 4,

	cout << "v5 == v6: " << (v5 == v6) << endl;
	cout << "v5 == v6: " << (v5 == v6) << endl;
	cout << "v5 < v6: " << (v5 < v6) << endl;
	cout << "v5 > v6: " << (v5 > v6) << endl;
	cout << "v6 == v7: " << (v6 == v7) << endl;

	// push_back pop_back
	v5.insert(v5.begin() + 1, 10); // 在begin的位置插入1个10，原来的元素向后移动
	print_vector(v5);
	v5.insert(v5.begin() + 1, 4, 10); // 在begin+1的位置插入4个10
	print_vector(v5);

	v5.erase(v5.begin());
	print_vector(v5);
	v5.erase(v5.begin(), v5.begin() + 3); // 将v5.begin() + 3之前的删除
	print_vector(v5);

	// 二维数组定义与初始化
	vector< vector<int> > b(10, vector<int>(5, 0));

	// sort 的使用
	int tobe_sort[20]={2,4,1,23,5,76,0,43,24,65};
	sort(tobe_sort, tobe_sort + 20, comp);
	print_vector(vector<int>(tobe_sort, tobe_sort + 20));

	return 0;
}