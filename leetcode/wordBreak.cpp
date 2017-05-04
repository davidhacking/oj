#include "./stdc++.h"

using namespace std;

struct Data {
    int index; // index of s
    int len; // dict len
    bool f;
    Data(int i, int l, bool f): index(i), len(l), f(f) {}
};

struct Comp {
    bool operator() (Data a, Data b) {
        if (a.index != b.index) {
            return a.index < b.index;
        } else {
            return a.len > b.len;
        }
    }
} comp;

void printData(vector<Data> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "(" << v[i].index << ", " << v[i].len << ")" << ", ";
    }
    cout << endl;
}

class Solution {
public:
    bool getString(vector<Data> &v, string &s, int start, vector<string> &ret, string t) {
        // if (start >= v.size()) {
        //     ret.push_back(t);
        //     return true;
        // }
        if (!v[start].f) {
            return false;
        }
        string tmp = (t == "" ? s.substr(v[start].index, v[start].len) : t + " " + s.substr(v[start].index, v[start].len));
        if (v[start].index + v[start].len == s.length()) {
            ret.push_back(tmp);
            return true;
        }
        int i = start;
        vector<int> next;
        while (i <= v.size() - 1) {
            while (i <= v.size() - 1 && v[i].index != v[start].index + v[start].len) {
                i++;
            }
            if (i <= v.size() - 1) {
                next.push_back(i);
                i++;
            }
        }
        bool f = false;
        for (int k = 0; k < next.size(); k++)
            if (next[k] <= v.size() - 1) {
                f |= getString(v, s, next[k], ret, tmp);
            }
        return v[start].f = f;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<Data> v;
        vector<string> ret;
        for (int i = 0; i < wordDict.size(); i++) {
            int t = -1;
            while ((t = s.find(wordDict[i], t + 1)) != string::npos) {
                v.push_back(Data(t, wordDict[i].size(), true));
            }
        }
        sort(v.begin(), v.end(), comp);
        // printData(v);
        for (int i = 0; i < v.size() && v[i].index == 0; i++)
            getString(v, s, i, ret, "");
        return ret;
    }
};

int main() {
    /*
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
Input:
"abcd"
["a","abc","b","cd"]
Output:
["abc","a b cd"]
Expected:
["a b cd"]

Input:
"aaaaaaa"
["aaaa","aa","a"]
Output:
["aaaa aa a","aa aaaa a","a aaaa aa"]
Expected:
["a a a a a a a","aa a a a a a","a aa a a a a","a a aa a a a","aa aa a a a","aaaa a a a","a a a aa a a","aa a aa a a"
    
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    */
    Solution *s = new Solution();

    // vector<string> wordDict;
    // wordDict.push_back("cat");
    // wordDict.push_back("cats");
    // wordDict.push_back("and");
    // wordDict.push_back("sand");
    // wordDict.push_back("dog");
    // vector<string> ret = s->wordBreak("catsanddog", wordDict);

    // vector<string> wordDict;
    // wordDict.push_back("aaaa");
    // wordDict.push_back("aa");
    // wordDict.push_back("a");
    // vector<string> ret = s->wordBreak("aaaaaaa", wordDict);

    vector<string> wordDict;
    wordDict.push_back("a");
    wordDict.push_back("aa");
    wordDict.push_back("aaa");
    wordDict.push_back("aaaa");
    wordDict.push_back("aaaaa");
    wordDict.push_back("aaaaaa");
    wordDict.push_back("aaaaaaa");
    wordDict.push_back("aaaaaaaa");
    wordDict.push_back("aaaaaaaaa");
    wordDict.push_back("aaaaaaaaaa");
    vector<string> ret = s->wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict);


    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ", " << endl;
    }
    cout << endl;
    return 0;
}