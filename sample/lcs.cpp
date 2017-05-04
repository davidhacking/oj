#include "./stdc++.h"
#include <stdio.h>
#include <string.h>
using namespace std;

/*
c[i, j] = 
0 if i==0 or j==0
c[i-1, j-1] + 1 if x[i]==y[j] 
max{c[i, j-1], c[i-1, j]} if x[i]!=y[j] // 这里的关键在于子问题都解决了c[i, j-1], c[i-1, j]

lt LEFT_TOP 0
l FROM_LEFT 1
t FROM_TOP 2

function lcs(x, y);
begin
	m = x.length;
	n = y.length;
	for i = 0 to m c[i, 0] = 0;
	for j = 0 to n c[0, j] = 0;
	for i = 1 to m
		for j = 1 to n
		begin
			if x[i]==y[j]
				c[i, j] = c[i-1, j-1] + 1;
				f[i, j] = (i-1, j-1);
			else if c[i, j-1] > c[i-1, j]
				c[i, j] = c[i, j-1];
				f[i, j] = (i, j-1);
			else 
				c[i, j] = c[i-1, j];
				f[i, j] = (i-1, j);
		end

function print_lcs(x, y, f, i, j, &ret)
	if i > 0 and j > 0
		if f[i, j].x==i-1 and f[i, j].y==j-1
			ret.insertFirst(x[i]);
		if f[i, j] == (i, j-1)
			print_lcs(x, y, f, i, j-1, &ret);
		if f[i, j] = (i-1, j)
			print_lcs(x, y, f, i-1, j, &ret);
*/

#define LEFT_TOP 0
#define FROM_LEFT 1
#define FROM_TOP 2

void print_lcs(const char *x, const char *y, vector<vector<int> > &f, int i, int j, vector<char> &ret) {
	if (i > 0 && j > 0) {
		if (f[i][j] == LEFT_TOP) {
			ret.insert(ret.begin(), x[i-1]);
			print_lcs(x, y, f, i-1, j-1, ret);
		} else if (f[i][j] == FROM_LEFT) {
			print_lcs(x, y, f, i, j-1, ret);
		} else if (f[i][j] == FROM_TOP) {
			print_lcs(x, y, f, i-1, j, ret);
		}
	}
}

void lcs(vector<vector<int> > &c, vector<vector<int> > &f, const char *x, const char *y) {
	if (x == NULL || y == NULL) {
		return;
	}
	int m = strlen(x);
	int n = strlen(y);
	if (m == 0 || n == 0) {
		return;
	}
	if (c.size() > 0) {
		c.clear();
	}
	if (f.size() > 0) {
		f.clear();
	}
	for (int i = 0; i <= m; i++) {
		c.push_back(vector<int>(n + 1, 0));
		f.push_back(vector<int>(n + 1, -1));
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				f[i][j] = LEFT_TOP;
			} else if (c[i][j-1] > c[i-1][j]) {
				c[i][j] = c[i][j-1];
				f[i][j] = FROM_LEFT;
			} else {
				c[i][j] = c[i-1][j];
				f[i][j] = FROM_TOP;
			}
		}
	}
	cout << "lcs.length: " << c[m][n] << endl;
	vector<char> ret;
	print_lcs(x, y, f, m, n, ret);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ", ";
	}
	cout << endl;
}

int main() {
	std::vector<std::vector<int> > c;
	std::vector<std::vector<int> > f;
	char x[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B', '\0'};
	char y[] = {'B', 'D', 'C', 'A', 'B', 'A', '\0'};
	lcs(c, f, x, y);
	return 0;
}