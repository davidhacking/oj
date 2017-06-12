//#include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;

int getMax(vector<int> &sub) {
    int currSum = 0;
    int max = INT_MIN;
    for (int i = 0; i < sub.size(); i++) {
    	if (currSum <= 0) {
    		currSum = sub[i];
    	} else {
    		currSum += sub[i]; 
    	}
    	max = std::max(max, currSum);
    }
    return max;
} 

int getTwoDivMax(vector<vector<int> > &m) {
 	if (m.size() <= 0 || m[0].size() <= 0) return 0;
	int max = m[0][0];
	for (int i = 0; i < m.size(); i++) {
		vector<int> sub(m[0].size(), 0);
		for (int j = i; j < m.size(); j++) {
			for(int k = 0; k < m[i].size(); k++) {
			 	sub[k] += m[j][k];
			}
			max = std::max(max, getMax(sub));
			cout << max << endl;
		}
	}
	return max;
}
int main() {
	int a[] = { 1, 2, -3,  1};
	int b[] = {-1, 2, -3,  1};
	int c[] = { 1, 2,  3, -1};
	vector<vector<int> > v;
	v.push_back(vector<int>(a, a+4));
	v.push_back(vector<int>(b, b+4));
	v.push_back(vector<int>(c, c+4));
	cout << getTwoDivMax(v) << endl;
	return 0;
}