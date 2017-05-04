// #include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;

int all_count;
int ln, rn;
char the_pattern[1024];


void dfs(vector<char>& v, int n, int left, int right);

void print_v(std::vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
}

void empty_v(std::vector<char>& v, int n) {
	v.erase(v.begin() + n);
}


void generate(int n) {
    std::vector<char> v;
    dfs(v, n, 0, 0);
}

bool find_pattern(std::vector<char>& v) {
	int a_len = strlen(the_pattern);
	int i = 0, j = 0;
	while (i < a_len && j < v.size()) {
		while (the_pattern[i] != v[j] && j < v.size()) {
			j++;
		}
		if (j == v.size() && v[j - 1] != the_pattern[i]) {
			return false;
		}
		i++; j++;
	}
	if (i == a_len && j <=v.size())
		return true;
	return false;
}

void dfs(vector<char>& v, int n, int left, int right) {
	// 剪枝
	if (left < right) {
		return;
	}
    if (2 * n == left + right) {
    	if (find_pattern(v)) {
    		// print_v(v);
    		all_count++;
    	}
        return;
    }
    if (left < n) {
        v.push_back('(');
        dfs(v, n, left + 1, right);
        empty_v(v, left + right);
    }
    if (right < left) {
        v.push_back(')');
        dfs(v, n, left, right + 1);
        empty_v(v, left + right);
    }
}


void count_ins(char *a, int a_len) {
	ln = 0; 
	rn = 0;
	for (int i = 0; i < a_len; i++) {
		if (a[i] == ')') {
			rn++;
		} else if (a[i] == '(') {
			ln++;
		}
	}
}

int add_ln() {
	int len = strlen(the_pattern);
	int need_to_add = 0;
	int ln_now = 0;
	for (int i = 0; i < len; i++) {
		if (the_pattern[i] == '(') {
			ln_now++;
		} else if (the_pattern[i] == ')') {
			if (ln_now <= 0) {
				need_to_add++;
			} else {
				ln_now--;
			}
		}
	}
	return need_to_add;
}

int main() {
	freopen("data1", "r", stdin);

	memset(the_pattern, 1024, 0);
	while (scanf("%s", the_pattern) != EOF) {
		int a_len = strlen(the_pattern);
		count_ins(the_pattern, a_len);
		int need_to_add = add_ln();
		ln += need_to_add;
		int ins = ln - rn + need_to_add;
		cout << "ins: " << ins << endl;
		int n = ln;
		// cout << "n: " << n << endl;
		if (ins == 0) {
			cout << ins << " " << 0 << endl;
			memset(the_pattern, 1024, 0);
			continue;
		}
		all_count = 0;
		generate(n);
		// cout << "all_count: " << all_count << endl;
		cout << ins << " " << all_count << endl;
		memset(the_pattern, 1024, 0);
	}
	return 0;
}