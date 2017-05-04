#include "./stdc++.h"

/*
在一个for循环中将该标记的都标记了，不用判断，例如标记素数
45的下一个数
450
46
5
*/

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
    	std::vector<int> v;
        int tmp = 1;
        for (int i = 0; i < n; i++) {
            v.push_back(tmp);
            if (tmp * 10 <= n) {
                tmp *= 10;
            } else if (tmp % 10 != 9 && tmp + 1 <= n) {
                tmp++;
            } else {
                while ((tmp / 10) % 10 == 9) {
                    tmp /= 10;
                }
                tmp /= 10;
                tmp++;
            }
        }
        return v;
    }
};

void print_v(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	Solution *s = new Solution();
	std::vector<int> v = s->lexicalOrder(13);
	print_v(v);
	return 0;
}