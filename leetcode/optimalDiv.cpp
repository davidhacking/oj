#include "./stdc++.h"

using namespace std;

class Solution {
public:
	// f=true min, f=false max pair<-1,-1>不加括号
	void opDiv(bool f, vector<int>& nums, int s, int e, vector<int> &ps) {
		if ((e - s + 1) <= 2) {
			if (ps.size() > 0) {
				ps.pop_back();
				ps.pop_back();
			}
		 	return; 
		}
		if (!f) {
			ps.push_back(s);
			ps.push_back(e);
			opDiv(!f, nums, s + 1, e, ps);
			return;
		}
		// if (f) {
		// 	ps.push_back(s);
		// 	ps.push_back(e);
		// 	opDiv(!f, nums, s + 1, e, ps);
		// 	return;
		// }
	}
    string optimalDivision(vector<int>& nums) {
    	if (nums.size() <= 0) return "";
    	if (nums.size() == 1) return std::to_string(nums[0]);
    	if (nums.size() == 2) return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
        // vector<int> &ps;
        // opDiv(false, nums, 0, ps);
        // sort(ps.begin(), ps.end());
        // int k = 0;
        string ret;
        for (int i = 0; i < nums.size(); i++) {
        	if (i == 0) {
        		ret += std::to_string(nums[i]) + "/" + "(";
        	} else if (i == ((int) nums.size() - 1)) {
        		ret += std::to_string(nums[i]) + ")";
        	} else {
        		ret += std::to_string(nums[i]) + "/";
        	}
        }
        return ret;
    }
};

int main() {
	return 0;
}