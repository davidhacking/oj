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

bool isEqual(TreeData *r1, TreeData *r2) {
	if (r1 == NULL && r2 == NULL) {
		return true;
	} else if (r1 != NULL && r2 == NULL) {
		return false;
	} else if (r1 == NULL && r2 != NULL) {
		return false;
	}
	if (r1->val == r2->val) {
		return isEqual(r1->left, r2->left) && isEqual(r1->right, r2->right);
	}
	return false;
}


int main() {
	TreeData *r1 = new TreeData(1);
	r1->left = new TreeData(2);
	r1->right = new TreeData(2);
	TreeData *r2 = new TreeData(1);
	r2->left = new TreeData(2);
	r2->right = new TreeData(2);
	cout << isEqual(r1, r2) << endl;
	cout << isEqual(r1, NULL) << endl;
	return 0;
}