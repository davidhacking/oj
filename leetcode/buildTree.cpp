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
    map<int, pair<int, int> > m;
    void buildTree(TreeNode* &root, vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        // cout << is << endl;
        // cout << ie << endl;
        // cout << ps << endl;
        // cout << pe << endl;
        // getchar();
        if (is > ie) {
            return;
        }
        root = new TreeNode(postorder[pe]);
        int mid = m[postorder[pe]].first;
        // cout << mid << endl;
        if ((mid - 1) >= is) {
            int len = mid - is;
            buildTree(root->left, inorder, is, mid - 1, postorder, ps, len + ps - 1);
        }
        if ((mid + 1) <= ie) {
            int len = ie - mid;
            buildTree(root->right, inorder, mid + 1, ie, postorder, pe - len, pe - 1);
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() <= 0 || postorder.size() <= 0) return NULL;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = pair<int, int>(i, 0);
        }
        for (int i = 0; i < postorder.size(); i++) {
            m[postorder[i]].second = i;
        }
        TreeNode* root = NULL;
        buildTree(root, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return root;
    }
};

int main() {
	int a[] = {1,3,2};
	int b[] = {3,2,1};
	vector<int> inorder(a, a+3);
	vector<int> postorder(b, b+3);
	Solution *s = new Solution();
	s->buildTree(inorder, postorder);
	return 0;
}