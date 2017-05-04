//#include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;

struct TreeData
{
	int val;
	TreeData *left;
	TreeData *right;
	TreeData(int v): val(v), left(NULL), right(NULL) {}
};

vector<int> getVector(TreeData *r) {
	vector<int> ret;
	if (r == NULL) {
		return ret;
	}
	vector<TreeData *> v1;
	v1.push_back(r);
	while (!v1.empty()) {
		ret.push_back(v1.back()->val);
		vector<TreeData *> v2;
		while (!v1.empty()) {
			TreeData *t = v1[0]; v1.erase(v1.begin());
			if (t->left != NULL) {
				v2.push_back(t->left);
			}
			if (t->right != NULL) {
				v2.push_back(t->right);
			}
		}
		v1.swap(v2);
	}
	return ret;
}

/*
   1            <---
 /   \
2     3         <---
 \     
  5     
*/

void print_v(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	TreeData *r1 = new TreeData(1);
	r1->left = new TreeData(2);
	r1->right = new TreeData(3);
	r1->left->right = new TreeData(5);
	print_v(getVector(r1));
	return 0;
}