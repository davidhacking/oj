#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/solutions
Time Limit Exceeded
167 / 169 test cases passed.
*/

void print_v(vector<int> &ret) {
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

void print_s(vector<string> &ret) {
	copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
	cout << endl;
}

struct Data {
	bool f;
	int i; // index in words

	Data(bool f, int i): f(f), i(i) {} 
};

struct Comp {
	vector<string>& words;
	Comp(vector<string>& w): words(w) {}
	int operator() (Data a, Data b) {
		// string A = words[a.i], B = words[b.i];
		// int flag = 0;
		// int i = 0;
		// for (; i < A.length(); i++) {
		// 	if (A[i] == B[i]) 
		// 		continue;
		// 	else {
		// 		flag = (int) A[i] - (int) B[i];
		// 		break;
		// 	}
		// }
		// flag *= (A.length() - i) * 26;
		// cout << A << ", " << B << " flag: " << flag << endl;
		// return flag;
		return words[a.i].compare(words[b.i]) < 0;
	} 
};

class Solution {
public:
	int compare(vector<string>& words, int a, string b) {
		return words[a].compare(b);
	} 
	int findStr(vector<string>& words, vector<Data> &ws, string t) {
		int s = 0, e = ws.size() - 1, m = s + (e - s) / 2;
		while (s <= e) {
			// cout << "s: " << s << " e: " << e << endl;
			m = s + (e - s) / 2;
			int x = compare(words, ws[m].i, t);
			if (x == 0) {
				if (ws[m].f)
					return m;
				else {
					for (int i = s; i <= e; i++) {
						if (words[ws[i].i].compare(t) == 0 && ws[i].f) return i;
					}
					return -1;
				}
			} else if (x < 0) {
				s = m + 1;
			} else {
				e = m - 1;
			}
		}
		return -1;
	}
	bool getIndex(string &s, int start, int end, int len, vector<string>& words, vector<Data> &ws) {
		if (start >= end) {
			return true;
		}

		int x = findStr(words, ws, s.substr(start, len));
    	if (x < 0) {
    		return false;
    	} else {
    		ws[x].f = false;
    		if (getIndex(s, start + len, end, len, words, ws)) {
    			ws[x].f = true;
    			return true;
    		}
    		ws[x].f = true;
    		return false;
    	}
	}
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> ret;
    	if (words.size() <= 0) return ret;
    	int len = words[0].length();
        vector<Data> ws;
        for (int i = 0; i < words.size(); i++) {
        	ws.push_back(Data(true, i));
        }
        Comp comp(words);
        sort(ws.begin(), ws.end(), comp);
        for (int i = 0; i < s.length(); i++) {
        	int x = findStr(words, ws, s.substr(i, len));
        	if (x >= 0) {
        		ws[x].f = false;
        		if (getIndex(s, i + len, i + len * (int) words.size(), len, words, ws)) {
        			ret.push_back(i);
        			if ((i + len * (int) words.size()) >= s.length()) {
        				break;
        			}
        		}
        		ws[x].f = true;
        	}
        }
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	/*
s: "barfoothefoobarman"
words: ["foo", "bar"]
	*/
	// string t = "barfoothefoobarman";
	// vector<string> v;
	// v.push_back("foo");
	// v.push_back("bar");

	/*
"pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel"
["dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"]
	*/
	string t = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
	string ss[] = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
	vector<string> v(ss, ss + sizeof(ss) / sizeof(ss[0]));
	cout << v.size() << endl;
	vector<int> ret = s->findSubstring(t, v);
	print_v(ret);
	return 0;
}