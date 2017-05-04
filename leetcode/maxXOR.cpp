#include "./stdc++.h"

using namespace std;

struct TreeData {
    TreeData *zero;
    TreeData *one;
    TreeData(): zero(NULL), one(NULL) {}
};

class Solution {
public:
    void buildTree(TreeData *&root, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            TreeData **node = &root;
            for (int k = 31; k >= 0; k--) {
                int x = (nums[i] >> k) & 1;
                if (!(*node)) *node = new TreeData();
                if (x == 0) {
                    if ((*node)->zero == NULL) 
                        (*node)->zero = new TreeData();
                    node = &((*node)->zero);
                } else {
                    if ((*node)->one == NULL) 
                        (*node)->one = new TreeData();
                    node = &((*node)->one);
                }
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        TreeData *root = NULL;
        buildTree(root, nums);
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            TreeData *node = root;
            int t = 0;
            for (int k = 31; k >= 0; k--) {
                t <<= 1;
                int x = (nums[i] >> k) & 1;
                if (x == 0) {
                    if (node->one) {
                        t |= 1;
                        node = node->one;
                    } else {
                        t |= 0;
                        node = node->zero;
                    }
                } else {
                    if (node->zero) {
                        t |= 1;
                        node = node->zero;
                    } else {
                        t |= 0;
                        node = node->one;
                    }
                }
            }
            ret = std::max(ret, t);
        }
        cout << ret << endl;
        return ret;
    }
};

int main() {
    int a[] = {3,10,5,25,2,8};
    vector<int> v(a, a+6);
    Solution *s = new Solution();
    s->findMaximumXOR(v);
    return 0;
}