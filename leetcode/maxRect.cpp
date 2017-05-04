#include "./stdc++.h"

using namespace std;

struct Comp {
    vector<int>& heights;
    bool operator() (int a, int b) {
        return heights[a] > heights[b];
    }
    Comp(vector<int> &h): heights(h) {}
};

class Solution {
public:
    // 超时
    int largestRectangleArea2(vector<int>& heights) {
        if (heights.size() <= 0) return 0;
        vector<int> index(heights.size(), 0);
        for (int i = 0; i < heights.size(); i++) {
            index[i] = i;
        }
        Comp comp(heights);
        sort(index.begin(), index.end(), comp);
        copy(index.begin(), index.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
        int ret = heights[index[0]];
        for (int i = 1; i < heights.size(); i++) {
            int h = heights[index[i]], x = index[i], y = index[i];
            while (x > 0 && heights[x - 1] >= h) 
                x--;
            while (y < heights.size() - 1 && heights[y + 1] >= h) 
                y++;
            cout << h << ", " << index[i] << ", " << x << ", " << y << endl;
            ret = std::max(ret, (y - x + 1) * h);
        }
        cout << ret << endl;
        return ret;
    }
    /*
    使用一个栈做这样的事情，即栈顶元素是栈中的最大元素，次大元素所在的位置的前一个位置是栈顶元素能够算到的位置

    */
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max = 0, t = 0;
        for (int i = 0; i < heights.size();) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i);
                i++;
            } else {
                t = s.top(); s.pop();
                max = std::max(max, heights[t] * (s.empty() ? i : i - s.top() - 1));
                cout << max << endl;
            }
        }
        while (!s.empty()) {
            t = s.top(); s.pop();
            max = std::max(max, heights[t] * (s.empty() ? (int) heights.size() : (int) heights.size() - s.top() - 1));
        }
        cout << max << endl;
        return max;
    }
};

int main() {
	Solution *s = new Solution();
	int a[] = {2,1,5,6,2,3,2,1,5,6,2,3,2,1,5,6,2,3,2,1,5,6,2,3,2,1,5,6,2,3};
	std::vector<int> v(a, a+30);
	s->largestRectangleArea(v);
	return 0;
}