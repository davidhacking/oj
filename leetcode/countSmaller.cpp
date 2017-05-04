#include "./stdc++.h"

using namespace std;

struct TreeData {
    int val;
    int smaller; // 统计这个节点的左树上有多少节点
    TreeData *left;
    TreeData *right;
    TreeData(int v, int s): left(NULL), right(NULL), val(v), smaller(s) {}
};
class Solution {
public:
    int countWithBT(TreeData *&root, int val, int count) {
        if (!root) {
            root = new TreeData(val, 0);
            return count;
        }
        if (root->val >= val) {
            root->smaller++;
            return countWithBT(root->left, val, count);
        }
        if (root->val < val) {
            count += root->smaller + 1;
            return countWithBT(root->right, val, count);
        }
        return count;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        TreeData *root = NULL;
        for (int i = ((int) nums.size() - 1); i >= 0; i--) {
            ret.push_back(countWithBT(root, nums[i], 0));
        }
        reverse(ret.begin(), ret.end());
        // free tree
        return ret;
    }
};

void print_v(vector<int> &ret) {
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ", ";
    }
    cout << endl;
}

int main() {
    Solution *s = new Solution();
    int a[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    vector<int> v(a, a+40);
    vector<int> ret = s->countSmaller(v);
    cout << ret.size() << endl;
    print_v(ret);
    return 0;
}