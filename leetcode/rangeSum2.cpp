#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/range-sum-query-mutable/#/description
利用线段树能够很好的求得range sum和update
线段树的结构数组线段开始下标，结束下标，线段和，左树为start到mid右树为mid+1到end
build树，采用递归的方法，终止条件为start=end，否则build左树，build右树，赋值sum
*/

struct SegTreeNode
{
	int start, end, sum;
	SegTreeNode *left, *right;
	SegTreeNode(int s, int e, int sum): start(s), end(e), sum(sum), left(NULL), right(NULL) {}
};

void buildSegTree(SegTreeNode *&root, vector<int> &nums, int start, int end) {
	if (start > end) {
		return;
	}
	if (start == end) {
		root = new SegTreeNode(start, end, nums[start]);
		return;
	}
	root = new SegTreeNode(start, end, 0);
	int mid = (start + end) >> 1;
	buildSegTree(root->left, nums, start, mid);
	buildSegTree(root->right, nums, mid + 1, end);
	root->sum = (root->left == NULL ? 0 : root->left->sum) + (root->right == NULL ? 0 : root->right->sum);
}

int rangeSumSegTree(SegTreeNode *&root, int i, int j) {
	if (root->start == i && root->end == j) {
		return root->sum;
	}
	int mid = (root->start + root->end) >> 1;
	if (j <= mid) {
		return rangeSumSegTree(root->left, i, j);
	} else if (i >= mid + 1) {
		return rangeSumSegTree(root->right, i, j);
	} else {
		return rangeSumSegTree(root->left, i, mid) + rangeSumSegTree(root->right, mid + 1, j);
	}
}

void updateSegTree(SegTreeNode *&root, int i, int val) {
	if (root == NULL || i < root->start || i > root->end) {
		return;
	}
	if (root->start == root->end && root->start == i) {
		root->sum = val;
		return;
	}
	int mid = (root->start + root->end) >> 1;
	if (root->start <= i && i <= mid) {
		root->sum -= root->left->sum;
		updateSegTree(root->left, i, val);
		root->sum += root->left->sum;
		return;
	}
	if (mid + 1 <= i && i <= root->end) {
		root->sum -= root->right->sum;
		updateSegTree(root->right, i, val);
		root->sum += root->right->sum;
		return;
	}
}

class NumArray {
public:
	SegTreeNode *root;
	vector<int> nums;
    NumArray(vector<int> nums) {
    	root = NULL;
    	this->nums = nums;
    	buildSegTree(root, nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
    	nums[i] = val;
    	updateSegTree(root, i, val);
    }
    
    int sumRange(int i, int j) {
        if (i == j) {
        	return nums[i];
        }
        return rangeSumSegTree(root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
	/*
	Given nums = [1, 3, 5]
	sumRange(0, 2) -> 9
	update(1, 2)
	sumRange(0, 2) -> 8
	*/
	int a[] = {1,3,5};
	vector<int> nums(a, a + 3);
	NumArray *obj = new NumArray(nums);
	cout << obj->sumRange(0, 2) << endl;
	obj->update(1, 2);
	cout << obj->sumRange(0, 2) << endl;
	return 0;
}