#include "./stdc++.h"

using namespace std;

struct BS
{
	int val;
	int index;
	BS *left;
	BS *right;
	BS(int v, int i): val(v), index(i), left(NULL), right(NULL) {}
};

void insertBS(BS *&root, int val, int index, BS *&parent) {
	if (root == NULL) {
		root = new BS(val, index);
		return;
	}
	if (root->val < val) {
		parent = root;
		insertBS(root->right, val, index, parent);
	} else {
		insertBS(root->left, val, index, parent);
	}
}

void find_max(BS *&node, vector<int> &f, int val, int *max) {
	if (node == NULL) {
		return;
	}
	// cout << "index: " << node->index << endl;
	if (f[node->index] + 1 > *max) {
		*max = f[node->index] + 1;
		// cout << "max: " << (*max) << endl;
	}
	find_max(node->left, f, val, max);
	if (node->right && val > node->right->val)
		find_max(node->right, f, val, max);
}

void print_v(vector<int> &f) {
	for (int i = 0; i < f.size(); i++) {
		cout << f[i] << ", ";
	}
	cout << endl;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.size() <= 0) {
    		return 0;
    	}
    	BS *root = NULL;
    	int max = 1;
    	BS *parent;
    	std::vector<int> f;
    	insertBS(root, nums[0], 0, parent);
    	f.push_back(1);
    	int all_max = 1;
        for (int i = 1; i < nums.size(); i++) {
        	max = 1;
        	parent = NULL;
        	insertBS(root, nums[i], i, parent);
        	//for (int k = 0; k < parent.size(); k++)
        	find_max(parent, f, nums[i], &max);
        	// cout << "find_max.max: " << max << endl;
        	f.push_back(max);
        	if (all_max < max) {
        		all_max = max;
        	}
        }
        // print_v(f);
        return all_max;
    }
};

int main() {
	Solution *s = new Solution();
	int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
	std::vector<int> v(a, a + 8);
	cout << (s->lengthOfLIS(v)) << endl;
	return 0;
}