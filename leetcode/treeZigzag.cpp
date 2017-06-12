#include "./stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(TreeNode* left, TreeNode* right, int x) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (root == NULL) return ret;
        queue<TreeNode*> nodes;
        
        nodes.push(root);
        nodes.push(NULL);
        ret.push_back(vector<int>());
        bool f = false; // 
        while (!nodes.empty()) {
            if (nodes.front() == NULL) {
            	if (f) {
            		reverse(ret.back().begin(), ret.back().end());
            		f = false;
            	} else {
            		f = true;
            	}
                ret.push_back(vector<int>());
                nodes.pop();
                if (nodes.empty()) {
                	return ret;
                }
                nodes.push(NULL);
                continue;
            }
            TreeNode* t = nodes.front(); nodes.pop();
            ret.back().push_back(t->val);
            if (t->left) {
                nodes.push(t->left);
            }
            if (t->right) {
                nodes.push(t->right);
            }
        }
        // ret.pop_back();
        return ret;
    }
};

void print_vv(vector<vector<int> > &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	Solution *s = new Solution();
/*
	3
   / \
  9  20
    /  \
   15   7
*/
   	TreeNode* root = new TreeNode(new TreeNode(9), new TreeNode(new TreeNode(15), new TreeNode(7), 20), 3);
   	vector<vector<int> > v = s->zigzagLevelOrder(root);
   	print_vv(v);
	return 0;
}