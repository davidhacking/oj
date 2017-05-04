#include "./stdc++.h"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
    	/* sliding window 方法
    		maxCount记录窗口中至今为止出现的最大值，maxLength为窗口的最大值
    		left为窗口左侧指针，right为窗口右侧指针，right指针向右滑动的过程中，每次更新maxCount，
    		以maxCount作为窗口中的最大长度字符移动left指针调整窗口大小，使得满足只能修改k个字符的要求，
    		这里面可能left会将maxCount的字符滑出去，这没关系
    	*/
    	int left = 0, right = 0, maxCount = 0, maxLength = 0;
    	vector<int> m(26, 0);
    	for (; right < s.size(); right++) {
    		maxCount = std::max(maxCount, ++m[s[right] - 'A']);
    		while (right - left + 1 - maxCount > k)
    			m[s[left++] - 'A']--;
    		maxLength = std::max(maxLength, right - left + 1);
    	}
    	return maxLength;
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->characterReplacement("AABABBA", 1) << endl;
	return 0;
}