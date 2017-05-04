
// #include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;
/*
4.1 12:25
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void print_tree(TreeNode* node) {
		if (node != NULL) {
			cout << node->val << ", ";
			print_tree(node->left);
			print_tree(node->right);
		}
	}
	TreeNode* find_node(TreeNode* node, int val, TreeNode* &p_node) {
		if (node == NULL) {
			return NULL;
		}
		if (node->val == val) {
			return node;
		}
		if (node->val > val) {
			p_node = node;
			return find_node(node->left, val, p_node);
		}
		if (node->val < val) {
			p_node = node;
			return find_node(node->right, val, p_node);
		}
		return NULL;
	}
    TreeNode* deleteNode(TreeNode* root, int val) {
        // O(deep of tree)
        if (root == NULL) {
        	return NULL;
        }
        if (root->val == val) {
        	if (root->left == NULL && root->right == NULL) {
        		delete root;
        		return NULL;
        	}
        	if (root->left != NULL && root->right == NULL) {
        		TreeNode* ret = root->left;
        		delete root;
        		return ret;
        	}
        	if (root->right != NULL && root->left == NULL) {
        		TreeNode* ret = root->right;
        		delete root;
        		return ret;
        	}
        	TreeNode* new_root = root->left;
        	TreeNode* nrr = new_root->right;
        	if (nrr == NULL) {
        	    new_root->right = root->right;
        	    delete root;
        	    return new_root;
        	}
        	new_root->right = root->right;
        	TreeNode* tmp = nrr;
        	while (tmp->right) {
        		tmp = tmp->right;
        	}
        	tmp->right = root->right->left;
        	new_root->right->left = nrr;
        	delete root;
        	return new_root;
        }
        TreeNode* p_node = root;
        TreeNode* node = find_node(root, val, p_node);
        // cout << node->val << endl;
        if (node != NULL) {
        	// 定义：p_node是被删除节点的父亲节点，node是被删节点，dl是node左儿子，dr是node的右儿子
        	// 		dll是dl的左儿子，dlr是dl的右儿子，drl是dr的左儿子，drr是dr的右儿子
        	// 被删节点的左儿子为空则使用右儿子替换node，删除结束
        	if (node->left == NULL) {
        		// cout << "node->left == NULL" << endl;
        		if (node == p_node->left) {
	        		p_node->left = node->right;
	        	} else {
	        		p_node->right = node->right;
	        	}
	        	delete node;
	        	return root;
        	}
        	// 被删节点的右儿子为空则使用左儿子替换node，删除结束
        	if (node->right == NULL) {
        		// cout << "node->right == NULL" << endl;
        		if (node == p_node->left) {
	        		p_node->left = node->left;
	        	} else {
	        		p_node->right = node->left;
	        	}
	        	delete node;
	        	return root;
        	}
        	TreeNode* dl = node->left;
        	// 使用被删节点的左儿子替换
        	if (node == p_node->left) {
        		p_node->left = dl;
        	} else {
        		p_node->right = dl;
        	}
        	// dl的右儿子为空，则dl的右儿子直接替换为dr，删除结束
        	if (dl->right == NULL) {
        		dl->right = node->right;
        		delete node;
	        	return root;
        	}
        	// 此时，dlr不为空，则将drl插入到dlr右子树的右叶子节点，并将dlr作为dr的左儿子
        	TreeNode* dlr = dl->right;
        	dl->right = node->right;
        	TreeNode* tmp = dlr;
        	while (tmp->right) {
        		tmp = tmp->right;
        	}
        	tmp->right = node->right->left;
        	dl->right->left = dlr;
        	delete node;
        	return root;
        }
        return root;
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

	TreeNode* new_root = s->deleteNode(root, 6);
	s->print_tree(new_root);
	return 0;
}
