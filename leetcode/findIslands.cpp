#include "./stdc++.h"

using namespace std;

void print_vv(vector<vector<int> > &ret) {
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

struct Data
{
	int x, y;
	Data(int x, int y): x(x), y(y) {}
};



class Solution {
public:
	void markAll(vector<vector<int> > &m, vector<vector<char> >& grid, int i, int j, int ret) {
		vector<Data> v;
		v.push_back(Data(i, j));
		while (!v.empty()) {
			Data d = v.back();
			v.pop_back();
			// top
			if (d.x - 1 >= 0 && grid[d.x - 1][d.y] == '1' && m[d.x - 1][d.y] == 0) {
				m[d.x - 1][d.y] = ret;
				v.push_back(Data(d.x - 1, d.y));
			}
			// right
			if (d.y + 1 <= grid[0].size() - 1 && grid[d.x][d.y + 1] == '1' && m[d.x][d.y + 1] == 0) {
				m[d.x][d.y + 1] = ret;
				v.push_back(Data(d.x, d.y + 1));
			}
			// bottom
			if (d.x + 1 <= grid.size() - 1 && grid[d.x + 1][d.y] == '1' && m[d.x + 1][d.y] == 0) {
				m[d.x + 1][d.y] = ret;
				v.push_back(Data(d.x + 1, d.y));
			}
			// left
			if (d.y - 1 >= 0 && grid[d.x][d.y - 1] == '1' && m[d.x][d.y - 1] == 0) {
				m[d.x][d.y - 1] = ret;
				v.push_back(Data(d.x, d.y - 1));
			}
		}
	}
    int numIslands(vector<vector<char> >& grid) {
    	int ret = 0;
    	if (grid.size() <= 0) {
    		return ret;
    	}
        vector<vector<int> > m(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
        	for (int j = 0; j < grid[i].size(); j++) {
        		if (grid[i][j] == '1' && m[i][j] == 0) {
        			m[i][j] = ++ret;
        			markAll(m, grid, i, j, ret);
        		}
        	}
        }
        return ret;
    }
};

int main() {
	/*
	11110
	11010
	11000
	00000
	*/
	Solution *s = new Solution();
	char a0[] = {'1','1','1','0','1'};
	char a1[] = {'1','1','0','1','0'};
	char a2[] = {'1','1','0','0','0'};
	char a3[] = {'0','0','0','0','0'};
	std::vector<char> v0(a0, a0 + 5);
	std::vector<char> v1(a1, a1 + 5);
	std::vector<char> v2(a2, a2 + 5);
	std::vector<char> v3(a3, a3 + 5);
	vector<vector<char> > v;
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	cout << s->numIslands(v) << endl;
	return 0;
}