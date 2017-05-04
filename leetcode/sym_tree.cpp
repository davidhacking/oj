
#include "./stdc++.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_v(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

class Solution {
public:
	void left_mid_right(TreeNode* left, std::vector<int> &v) {
		if (left != NULL) {
			left_mid_right(left->left, v);
			v.push_back(left->val);
			left_mid_right(left->right, v);
		}
	}
	void right_mid_left(TreeNode* node, std::vector<int> &v) {
		if (node != NULL) {
			right_mid_left(node->right, v);
			v.push_back(node->val);
			right_mid_left(node->left, v);
		}
	}
    bool isSymmetric(TreeNode* root) {
    	if (!root || (!root->left && !root->right)) {
    		return true;
    	}
    	if ((!root->left && root->right) || (root->left && !root->right)) {
    		return false;
    	}
    	if (root->left->val != root->right->val) {
    		return false;
    	}
        std::vector<int> l;
        std::vector<int> r;
        left_mid_right(root->left, l);
        right_mid_left(root->right, r);
        if (l.size() != r.size()) {
        	return false;
        }
        for (int i = 0; i < l.size(); i++) {
        	if (l[i] != r[i]) {
        		return false;
        	}
        }
        return true;
    }
};


int main() {
	Solution *s = new Solution();
	cout << (s->isSymmetric(NULL)) << endl;
	TreeNode *root = new TreeNode(1);
	cout << (s->isSymmetric(root)) << endl;
	TreeNode *a = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(4);
	a->left = c;
	a->right = d;
	TreeNode *b = new TreeNode(2);
	TreeNode *e = new TreeNode(4);
	TreeNode *f = new TreeNode(3);
	b->left = e;
	b->right = f;

	root->left = a;
	root->right = b;
	cout << (s->isSymmetric(root)) << endl;
	return 0;
}