#include "./stdc++.h"

using namespace std;

class Solution {
public:
    // mem limit executed
    bool isRectangleCover2(vector<vector<int> >& rectangles) {
        // 找左边最小的点，找右边最大的点
        int x1 = INT_MIN, x0 = INT_MAX, y1 = INT_MIN, y0 = INT_MAX, min = 0, max = 0, sr = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            if (x0 > rectangles[i][0]) {
                x0 = rectangles[i][0];
                min = i;
            }
            if (y0 > rectangles[i][1]) {
                y0 = rectangles[i][1];
                min = i;
            }
            if (x1 < rectangles[i][2]) {
                x1 = rectangles[i][2];
                max = i;
            }
            if (y1 < rectangles[i][3]) {
                y1 = rectangles[i][3];
                max = i;
            }
            sr += (rectangles[i][3] - rectangles[i][1]) * (rectangles[i][2] - rectangles[i][0]);
        }
        // cout << "min: " << min << " max: " << max << endl;
        // cout << "x0: " << x0 << " x1: " << x1 << " y0: " << y0 << " y1: " << y1 << " sr: " << sr << endl;
        // cout << (rectangles[min][1] != y0) << endl;
        // cout << (rectangles[max][3] != y1) << endl;
        // cout << (sr != ((y1 - y0) * (x1 - x0))) << endl;
        if (sr != ((y1 - y0) * (x1 - x0))) {
            return false;
        }
        // 以上只是必要条件
        /*
        [[0,0,1,1],[0,1,3,2],[1,0,2,2]]
        */
        int sr2 = 0;
        vector<vector<int> > t(x1 - x0, vector<int>(y1 - y0, 0));
        for (int i = 0; i < rectangles.size(); i++) {
            for (int x = rectangles[i][0]; x < rectangles[i][2]; x++) {
                for (int y = rectangles[i][1]; y < rectangles[i][3]; y++) {
                    if ((x - x0) <= (x1 - x0 - 1) && (y - y0) <= (y1 - y0 - 1) && t[x - x0][y - y0] == 0) {
                        t[x - x0][y - y0] = 1;
                        sr2++;
                    } else {
                        return false;
                    }
                }
            }
        }
        // cout << sr2 << endl;
        return sr2 == sr;
    }
    void add(pair<int, int> &p, map<pair<int, int>, bool> &m) {
        if (m.count(p) <= 0) {
            m[p] = true;
        } else {
            m.erase(m.find(p));
        }
    }
    bool isRectangleCover(vector<vector<int> >& rectangles) {
        /*
        一个长方形只能是4个点，所以可以不断的add每一个长方形并且替换里面的点集
        */
        int x1 = INT_MIN, x0 = INT_MAX, y1 = INT_MIN, y0 = INT_MAX, min = 0, max = 0, sr = 0;
        map<pair<int, int>, bool> m;
        for (int i = 0; i < rectangles.size(); i++) {
            if (x0 > rectangles[i][0]) {
                x0 = rectangles[i][0];
                // min = i;
            }
            if (y0 > rectangles[i][1]) {
                y0 = rectangles[i][1];
                // min = i;
            }
            if (x1 < rectangles[i][2]) {
                x1 = rectangles[i][2];
                // max = i;
            }
            if (y1 < rectangles[i][3]) {
                y1 = rectangles[i][3];
                // max = i;
            }
            pair<int, int> top(rectangles[i][0], rectangles[i][3]);
            pair<int, int> right(rectangles[i][2], rectangles[i][3]);
            pair<int, int> bottom(rectangles[i][2], rectangles[i][1]);
            pair<int, int> left(rectangles[i][0], rectangles[i][1]);
            add(top, m);
            add(right, m);
            add(bottom, m);
            add(left, m);
            sr += (rectangles[i][3] - rectangles[i][1]) * (rectangles[i][2] - rectangles[i][0]);
        }
        pair<int, int> top(x0, y1);
        pair<int, int> right(x1, y1);
        pair<int, int> bottom(x1, y0);
        pair<int, int> left(x0, y0);
        if (m.size() != 4 || m.count(top) <= 0 || m.count(right) <= 0 || m.count(bottom) <= 0 || m.count(left) <= 0)
            return false; 
        return sr == ((y1 - y0) * (x1 - x0));
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int> > r;
    // int a0[] = {1,1,3,3};
    // int a1[] = {3,1,4,2};
    // int a2[] = {3,2,4,4};
    // int a3[] = {1,3,2,4};
    // int a4[] = {2,3,3,4};

    /*
    [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
    */
    int a0[] = {1,1,3,3};
    int a1[] = {3,1,4,2};
    int a2[] = {3,2,4,4};
    int a3[] = {1,3,2,4};
    int a4[] = {2,3,3,4};
    vector<int> v0(a0, a0+4);
    vector<int> v1(a1, a1+4);
    vector<int> v2(a2, a2+4);
    vector<int> v3(a3, a3+4);
    vector<int> v4(a4, a4+4);
    r.push_back(v0);
    r.push_back(v1);
    r.push_back(v2);
    r.push_back(v3);
    r.push_back(v4);
    cout << s->isRectangleCover(r) << endl;
    return 0;
}