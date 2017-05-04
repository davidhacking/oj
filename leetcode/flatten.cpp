
#include "./stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isReady(TreeNode *node) {
		if (node == NULL) {
			return true;
		}
		TreeNode *tmp = node;
		while (tmp != NULL) {
			if (tmp->left != NULL) {
				return false;
			}
			tmp = tmp->right;
		}
		return true;
	}
    void flatten(TreeNode* root) {
        if (root == NULL) {
        	return;
        }
        if (!isReady(root->left)) {
        	flatten(root->left);
        }
        if (!isReady(root->right)) {
        	flatten(root->right);
        }
        // flatten left to right
        if (root->left == NULL) {
        	return;
        }
        TreeNode *t1 = root->left;
        TreeNode *t2 = root->right;
        root->right = root->left;
        // 如果没有这句函数退出时可能会有double free的危险
        root->left = NULL;
        while (t1->right != NULL) {
        	t1 = t1->right;
        }
        t1->right = t2;
    }
};

int main() {
	/*
		NULL
	*/
	/*
		1
	*/
	/*
		1
	   / 
	  2
	*/
	  TreeNode *root = new TreeNode(1);
	  root->left = new TreeNode(2);
	 /*
	    1
	     \ 
	      2
	 */
	/*
	 	 1
        / \
       2   5
      / \   \
     3   4   6
	*/
     /*
		 1
        / \
       2   5
      / \   \
     3   4   6
    / \  / \
   4   5 8  9
     */
   Solution *s = new Solution();
   s->flatten(root);
	return 0;
}