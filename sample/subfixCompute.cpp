#include "./stdc++.h"

using namespace std;

map<char, int> table;


string infix2subfix(string s) {
	stack<char> st;
	string ret;
	
	/*
	操作数直接输出
	运算符与栈顶元素比较优先级大于等于则入栈，否则弹出栈顶元素输出直到栈顶小于然后入站
	括号不同，左优先级最高，并且只有有括号才能使其出栈
	*/
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '(' && s[i] != ')' && table.count(s[i]) <= 0) {
			ret.push_back(s[i]);
		} else if (s[i] == '(') {
			st.push(s[i]);
		} else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				ret.push_back(st.top());
				st.pop();
			}
			st.pop();// check
		} else {
			if (st.empty() || table[st.top()] <= table[s[i]]) {
				st.push(s[i]);
			} else {
				while (!st.empty() && table[st.top()] > table[s[i]]) {
					ret.push_back(st.top());
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) {
		ret.push_back(st.top());
		st.pop();
	}
	cout << ret << endl;
	return ret;
}

int compute(string s) {
	stack<int> st;
	string t = infix2subfix(s);
	string tmp = "";
	for (int i = 0; i < t.length(); i++) {
		if (table.count(t[i]) <= 0) {
			tmp.push_back(t[i]);
			st.push((int) t[i] - '0');
		} else if (t[i] == '+') {
			st.push();
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			st.push(a + b);
		} else if (t[i] == '-') {
			st.push((int) t[i] - '0');
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			st.push(b - a);
		} else if (t[i] == '*') {
			st.push((int) t[i] - '0');
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			st.push(a * b);
		}
	}
	cout << st.size() << endl;
	return st.top();
}

int main() {
	table['+'] = 1;
	table['-'] = 1;
	table['*'] = 2;
	table['/'] = 2;
	//table['('] = 3;

	string s = "1+2*3-4";//3
	string s2 = "1+2*(3-4)";//-1
	string s3 = "1+2*(3-4)/2";//0
	string s4 = "10+20*(3-4)/2/5";//8
	cout << compute(s) << endl;
	cout << compute(s2) << endl;
	cout << compute(s3) << endl;
	cout << compute(s4) << endl;
	return 0;
}