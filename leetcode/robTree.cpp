#include "./stdc++.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    pair<int, int> rob2(TreeNode* node) {
        pair<int, int> p(0, 0), pl(0, 0), pr(0, 0);
        if (!node) return p;
        if (node->left) {
            pl = rob2(node->left);
        }
        if (node->right) {
            pr = rob2(node->right);
        }
        p.first = std::max(std::max(std::max(pl.first + pr.first, pl.first + pr.second), pl.second + pr.first), pl.second + pr.second);
        p.second = pl.first + pr.first + node->val;
        return p;
    }
    int rob(TreeNode* root) {
        pair<int, int> p = rob2(root);
        return std::max(p.first, p.second);
    }
};

int main() {
    //[2,1,3,null,4]
    TreeNode *root = new TreeNode(2, new TreeNode(1, NULL, new TreeNode(4)), new TreeNode(3));
    Solution *s = new Solution();
    cout << s->rob(root) << endl;
    return 0;
}