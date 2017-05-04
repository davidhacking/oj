#include "./stdc++.h"

/*
memory limited
*/
using namespace std;
struct DictNode;
struct DictEdge
{
	char c;
	int count;
	DictNode *node;
	DictEdge(char x): c(x), count(0), node(NULL) {}
};
struct DictNode
{
	int count;
	map<char, DictEdge *> m;
	DictNode(): count(0), m(map<char, DictEdge *>()) {}
};
void put_str_dict(DictNode **root, string s) {
	DictNode **node = root;
	for (int i = 0; i < s.length(); i++) {
		if (!(*node)) {
			*node = new DictNode();
		}
		(*node)->count++;
		if ((*node)->m[s[i]] == NULL) {
			(*node)->m[s[i]] = new DictEdge(s[i]);
		}
		(*node)->m[s[i]]->count++;
		node = &((*node)->m[s[i]]->node);
	}
}
void get_dict(std::vector<string> &ret, string use, DictNode *node) {
	for (map<char, DictEdge *>::iterator i = (node->m).begin(); i != (node->m).end(); i++) {
		string str = use;
		char c = i->first;
		DictEdge *edge = i->second;
		str.push_back(c);
		if (edge->node && edge->count > edge->node->count) {
			ret.push_back(str);
		}
		if (edge->node == NULL) {
			// 返回当前str
			ret.push_back(str);
			// erase最后一位，重新构建str
			str.erase(str.length() - 1);
		} else {
			get_dict(ret, str, edge->node);
		}
	}
}

void get_dict(std::vector<int> &ret, string use, DictNode *node) {
	stringstream ss;
	for (map<char, DictEdge *>::iterator i = (node->m).begin(); i != (node->m).end(); i++) {
		string str = use;
		char c = i->first;
		DictEdge *edge = i->second;
		str.push_back(c);
		if (edge->node && edge->count > edge->node->count) {
			// ret.push_back(str);
			ss.clear();
			ss << str;
			int tmp;
			ss >> tmp;
			ret.push_back(tmp);
		}
		if (edge->node == NULL) {
			// 返回当前str
			ss.clear();
			ss << str;
			int tmp;
			ss >> tmp;
			ret.push_back(tmp);
			// erase最后一位，重新构建str
			str.erase(str.length() - 1);
		} else {
			get_dict(ret, str, edge->node);
		}
	}
}
std::vector<string> print_dict(DictNode *root) {
	vector<string> ret;
	if (!root) {
		return ret;
	}
	get_dict(ret, "", root);
	return ret;
}
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        std::vector<int> v;
        stringstream ss;
        DictNode *root = NULL;
        for (int i = 1; i <= n; i++) {
        	ss.clear();
        	ss << i;
        	string tmp;
        	ss >> tmp;
        	put_str_dict(&root, tmp);
        }
        get_dict(v, "", root);
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
	std::vector<int> v = s->lexicalOrder(10458);
	print_v(v);
	return 0;
}