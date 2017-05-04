#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/spiral-matrix/#/description

class Solution {
public:
	void getSpiralOrder(vector<vector<int> >& m, vector<int>& ret, int ms, int me, int ns, int ne) {
        for (int i = ns; i <= ne; i++)
        {
			ret.push_back(m[ms][i]);
			cout << "1. " << m[ms][i] << endl;
        }
		for (int i = ms + 1; i <= me; i++)
		{
			ret.push_back(m[i][ne]);
			cout << "2. " << m[i][ne] << endl;
		}
		if (me > ms)
			for (int i = ne - 1; i >= ns; i--)
			{
				ret.push_back(m[me][i]);
				cout << "3. " << m[me][i] << endl;
				cout << "3. ne: " << ne << " ns: " << ns << endl;
			}
		if (ne > ns)
			for (int i = me - 1; i >= ms + 1; i--)
			{
				ret.push_back(m[i][ns]);
				cout << "4. " << m[i][ns] << endl;
			}
    }
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
		if (matrix.size() <= 0) {
            return ret;
        }
		int ms = 0, me = matrix.size() - 1, ns = 0, ne = matrix[0].size() - 1, i = 0;
		while (ms <= me && ns <= ne)
		{
			ms += i;
			me -= i;
			ns += i;
			ne -= i;
			cout << "ms: " << ms << " me: " << me << " ns: " << ns << " ne: " << ne << endl;
			if (!(ms <= me && ns <= ne))
			{
				break;
			}
			getSpiralOrder(matrix, ret, ms, me, ns, ne);
			i = 1;
		}
		return ret;
    }
};

void print_v(vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	Solution *s = new Solution();
	/*
	[
	 [ 1, 2, 3 ],
	 [ 4, 5, 6 ],
	 [ 7, 8, 9 ]
	]
	*/
	/*
	int a0[] = {1, 2, 3};	
	int a1[] = {4, 5, 6};
	int a2[] = {7, 8, 9};
	vector<int> v0(a0, a0 + 3);
	vector<int> v1(a1, a1 + 3);
	vector<int> v2(a2, a2 + 3);
	vector<vector<int> > v;
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	*/

	/*
	[[2,3]]
	*/
	/*
	int a0[] = {2, 3};
	vector<int> v0(a0, a0 + 2);
	vector<vector<int> > v;
	v.push_back(v0);
	*/
	
	/*
	[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
	*/
	int a0[] = {1,2,3,4,5};	
	int a1[] = {6,7,8,9,10};
	int a2[] = {11,12,13,14,15};
	int a3[] = {16,17,18,19,20};
	int a4[] = {21,22,23,24,25};
	vector<int> v0(a0, a0 + 5);
	vector<int> v1(a1, a1 + 5);
	vector<int> v2(a2, a2 + 5);
	vector<int> v3(a3, a3 + 5);
	vector<int> v4(a4, a4 + 5);
	vector<vector<int> > v;
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	vector<int> x = s->spiralOrder(v);
	print_v(x);
	return 0;
}