#include <stack>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int test_case_number = 0;
int half_parenthesis_length = 0;
int p_seq[125];
char parenthesis_str[255];
int parenthesis_str_index = 0;

int get_matched_left_parenthesis_index(int right_index) {
	stack<int> left;
	// cout << "right_index " << right_index << endl;
	for (int i = 0; i < parenthesis_str_index; i++) {
		if (parenthesis_str[i] == ')') {
			if (i == right_index) {
				// cout << "left_index " << left.top() << endl;
				return left.top();
			}
			left.pop();
		} else if (parenthesis_str[i] == '(') {
			left.push(i);
		}
	}
	return -1;
}

void print_w_seq() {
	for (int i = 0; i < parenthesis_str_index; i++) {
		if (parenthesis_str[i] == ')') {
			int left = get_matched_left_parenthesis_index(i);
			if (left == -1) {
				cout << "return -1 error" << endl;
			}
			int tmp = (i - left + 1) / 2;
			cout << tmp << " ";

		}
	}
	cout << endl;
}

/*

S			(((()()())))

P-sequence	    4 5 6666

W-sequence	    1 1 1456
*/

int main() {
	// freopen("/Users/david/myFile/OJ/poj1068/test.data", "r", stdin);
	while (true) {
		if (scanf("%d", &test_case_number) == EOF || test_case_number <= 0) {
			return 0;
		}
		memset(p_seq, 0, 125 * sizeof(int));
		for (int i = 0; i < test_case_number; i++) {
			scanf("%d", &half_parenthesis_length);
			memset(parenthesis_str, 0, 125);
			parenthesis_str_index = 0;
			for (int j = 0; j < half_parenthesis_length; j++) {
				scanf("%d", &p_seq[j]);
				// restore_parenthesis_str
				if (j == 0 && p_seq[j] > 0) {
					for (int k = 0; k < p_seq[j]; k++) {
						parenthesis_str[parenthesis_str_index++] = '(';
					}
					parenthesis_str[parenthesis_str_index++] = ')';
				}
				if (j > 0 && p_seq[j] > 0) {
					int tmp = p_seq[j] - p_seq[j - 1];
					for (int k = 0; k < tmp; k++) {
						parenthesis_str[parenthesis_str_index++] = '(';
					}
					parenthesis_str[parenthesis_str_index++] = ')';
				}
			}
			// cout << "parenthesis_str: " << parenthesis_str << endl;

			
			// read w_seq
			print_w_seq();
		}
	}
	return 0;
}