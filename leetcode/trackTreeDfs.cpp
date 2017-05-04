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
    string toString(int i) {
        stringstream ss;
        string tmp;
        tmp = "";
        ss << i;
        ss >> tmp;
        return tmp;
    }
    void binaryTreePaths(TreeNode* root, vector<string> &ret, string &t) {
        if (root != NULL) {
            t += toString(root->val);
            if (root->left == NULL && root->right == NULL) {
                ret.push_back(t);
                return;
            }
            t += "->";
            if (root->left != NULL) {
                string ls = t;
                binaryTreePaths(root->left, ret, ls);
            }
            if (root->right != NULL) {
                string rs = t;
                binaryTreePaths(root->right, ret, rs);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL) {
            return ret;
        }
        string t = "";
        binaryTreePaths(root, ret, t);
        return ret;
    }
};

int main () {
    TreeNode *root = new TreeNode(1);
    TreeNode *l = new TreeNode(2);
    TreeNode *r = new TreeNode(3);
    root->left = l;
    root->right = r;
    l->right = new TreeNode(5);
    Solution *s = new Solution();
    vector<string> v = s->binaryTreePaths(root);
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}