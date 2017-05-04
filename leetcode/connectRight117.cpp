//#include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;




struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void copyQueue(queue<TreeLinkNode *> &dst, queue<TreeLinkNode *> &src) {
		while (!dst.empty()) {
			dst.pop();
		}
		std::vector<TreeLinkNode *> v;
		while (!src.empty()) {
			v.push_back(src.front());
			src.pop();
		}
		for (int i = 0; i < v.size(); i++) {
			dst.push(v[i]);
			src.push(v[i]);
		}
	}
    void connect(TreeLinkNode *root) {
    	if (root == NULL) {
            return;
        }
        queue<TreeLinkNode *> q1;
        q1.push(root);
    	queue<TreeLinkNode *> q2;
    	queue<TreeLinkNode *> q3;
    	TreeLinkNode *head = NULL;
    	TreeLinkNode *next = NULL;

    label:
    	if (q1.empty()) {
    		return;
    	}
    	while (!q1.empty()) {
    		if (q1.front()->left) {
    			q2.push(q1.front()->left);
    		}
    		if (q1.front()->right) {
    			q2.push(q1.front()->right);
    		}
    		q1.pop();
    	}
    	// add connect
    	if (!q2.empty()) {
	    	copyQueue(q3, q2);
	    	head = q3.front();
	    	q3.pop();
	    	while (!q3.empty()) {
	    		next = q3.front(); q3.pop();
	    		head->next = next;
	    		head = next;
	    	}
	    	head->next = NULL;
	    	q1.swap(q2);
	    	goto label;
	    }
    }
};

/*
3.31 9:00
*/
int main() {
	Solution *s = new Solution();
	TreeLinkNode* one = new TreeLinkNode(1);
	TreeLinkNode* two = new TreeLinkNode(2);
	one->left = two;
	s->connect(one);
	return 0;
}