#include "./stdc++.h"

using namespace std;

class Solution {
public:
//     int jump(vector<int>& nums) {
//         /*
// 广度优先搜索，记录深度
//         */
// 		int aim = nums.size() - 1;
// 		queue<int> q;
// 		q.push(0);
// 		q.push(-1);
// 		int ret = 0;
// 		while (!q.empty()) {
// 			int t;
// 			if ((t = q.front()) >= aim) {
// 				break;
// 			}
// 			q.pop();
// 			cout << t << endl;
// 			if (t == -1) {
// 				ret++;
// 				if (q.size() <= 0) {
// 					break;
// 				}
// 				q.push(-1);
// 				continue;
// 			}
// 			for (int j = 1; j <= nums[t]; j++) {
// 				q.push(j + t);
// 			}
// 		}
// 		return ret;
//     }
    int jump(vector<int>& nums) {
    	int a, b, t, len = nums.size() - 1;
    	a = 0; // a表示当前能到达的最远index
    	b = 0; // b表示步数
    	t = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		if (a >= len) {
    			break;
    		}
    		if (i > a) {
    			b++;
    			a = t;
    		}
    		if ((i + nums[i]) > t) {
    			t = i + nums[i];
    		}
    	}
    	return b;
    }
};

int main() {
	Solution *s = new Solution();
	int a[] = {2,3,1,1,4};
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	int a2[] = {0};
	vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
	int a3[] = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
	vector<int> v3(a3, a3 + sizeof(a3) / sizeof(a3[0]));
	cout << s->jump(v) << endl;
	cout << s->jump(v2) << endl;
	cout << s->jump(v3) << endl;
	return 0;
}