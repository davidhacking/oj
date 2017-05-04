
// #include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;
/*
4.1
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_vector(std::vector<int> _v) {
    for (int i = 0; i < _v.size(); i++) {
        cout << _v[i] << ", ";
    }
    cout << endl;
}

class Solution {
public:
    TreeNode *mstack[10000];
    int index;
    void push(TreeNode *e) {
        // cout << "push: " << index << endl;
        mstack[index++] = e;
    }
    TreeNode *pop() {
        // cout << "pop: " << index << endl;
        return mstack[--index];
    }
	vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<int> s;
        // stack<TreeNode *> s;
        TreeNode *node = root;
        index = 0;
        // while (!s.empty() || node != NULL) {
        while (index > 0 || node != NULL) {
            if (node != NULL) {
                // ret.insert(ret.begin(), node->val);
                s.push(node->val);
                // s.push(node);
                push(node);
                node = node->right;
            } else {
                // node = s.top(); s.pop();
                node = pop();
                node = node->left;
            }
        }
        while (!s.empty()) {
            ret.push_back(s.top()); s.pop();
        }
        return ret;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        // stack<TreeNode *> s;
        TreeNode *node = root;
        index = 0;
        // while (!s.empty() || node != NULL) {
        while (index > 0 || node != NULL) {
            if (node != NULL) {
                ret.push_back(node->val);
                // s.push(node);
                push(node);
                node = node->left;
            } else {
                // node = s.top(); s.pop();
                node = pop();
                node = node->right;
            }
        }
        return ret;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        // stack<TreeNode *> s;
        TreeNode *node = root;
        index = 0;
        // while (!s.empty() || node != NULL) {
        while (index > 0 || node != NULL) {
            if (node != NULL) {
                // s.push(node);
                push(node);
                node = node->left;
            } else {
                // node = s.top(); s.pop();
                node = pop();
                ret.push_back(node->val);
                node = node->right;
            }
        }
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	TreeNode *root = new TreeNode(5);
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(6);
	TreeNode *c = new TreeNode(2);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(7);

	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->right = e;

	vector<int> v;
    v = s->postorderTraversal(root);
	print_vector(v);
    v = s->preorderTraversal(root);
    print_vector(v);
    v = s->inorderTraversal(root);
    print_vector(v);
	return 0;
}
