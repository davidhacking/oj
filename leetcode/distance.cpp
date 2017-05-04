#include "./stdc++.h"

using namespace std;

struct Data
{
	int x;
	int y;
	Data(int x, int y): x(x), y(y) {}
};

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
    	if (matrix.size() <= 0) {
    		return vector<vector<int> >();
    	}
        vector<Data> v;
        vector<vector<int> > ret(matrix.size(), vector<int>(matrix[0].size(), -1));
        int iter = 0, m = matrix.size(), n = matrix[0].size(), nums = m * n, dis = 0;
        for (int i = 0; i < matrix.size(); i++) {
        	for (int j = 0; j < matrix[i].size(); j++) {
        		if (matrix[i][j] == 0) {
        			v.push_back(Data(i, j));
        			ret[i][j] = 0;
        			iter++;
        		}
        	}
        }
        dis++;
        while (iter < nums) {
        	vector<Data> t;
        	while (!v.empty()) {
        		// top
        		if (v.back().x - 1 >= 0 && ret[v.back().x - 1][v.back().y] == -1) {
        			ret[v.back().x - 1][v.back().y] = dis; iter++;
        			t.push_back(Data(v.back().x - 1, v.back().y));
        		}
        		// right
        		if (v.back().y + 1 <= n - 1 && ret[v.back().x][v.back().y + 1] == -1) {
        			ret[v.back().x][v.back().y + 1] = dis; iter++;
        			t.push_back(Data(v.back().x, v.back().y + 1));
        		}
        		// bottom
        		if (v.back().x + 1 <= m - 1 && ret[v.back().x + 1][v.back().y] == -1) {
        			ret[v.back().x + 1][v.back().y] = dis; iter++;
        			t.push_back(Data(v.back().x + 1, v.back().y));
        		}
        		// left
        		if (v.back().y - 1 >= 0 && ret[v.back().x][v.back().y - 1] == -1) {
        			ret[v.back().x][v.back().y - 1] = dis; iter++;
        			t.push_back(Data(v.back().x, v.back().y - 1));
        		}
        		v.pop_back();
        	}
        	v = t;
        	dis++;
        }
        return ret;
    }
};

void print_vv(vector<vector<int> > &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	Solution *s = new Solution();
	int a0[] = {0, 0, 0};
	int a1[] = {0, 0, 0};
	int a2[] = {0, 0, 0};
	vector<vector<int> > v;
	vector<int> v0(a0, a0 + 3);
	vector<int> v1(a1, a1 + 3);
	vector<int> v2(a2, a2 + 3);
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	vector<vector<int> > ret = s->updateMatrix(v);
	print_vv(ret);
	return 0;
}