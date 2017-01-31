#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;


#define K(w, x)	(w && x)
#define A(w, x)	(w || x)
#define N(w)	(!w)
#define C(w, x) ((w == 1 && x == 0) ? 0 : 1)
#define E(w, x) (w == x)

int p, q, r, s, t;
char input[125];

bool compute_express() {
	stack<int> _stack;
	int input_len = strlen(input);
	for (int i = input_len - 1; i >= 0; i--) {
		if (input[i] == 'p') {
			_stack.push(p);
			continue;
		}
		if (input[i] == 'q') {
			_stack.push(q);
			continue;
		}
		if (input[i] == 'r') {
			_stack.push(r);
			continue;
		}
		if (input[i] == 's') {
			_stack.push(s);
			continue;
		}
		if (input[i] == 't') {
			_stack.push(t);
			continue;
		}
		if (input[i] == 'K') {
			int w = _stack.top();
			_stack.pop();
			int x = _stack.top();
			_stack.pop();
			_stack.push(K(w, x));
			continue;
		}
		if (input[i] == 'A') {
			int w = _stack.top();
			_stack.pop();
			int x = _stack.top();
			_stack.pop();
			_stack.push(A(w, x));
			continue;
		}
		if (input[i] == 'N') {
			int w = _stack.top();
			_stack.pop();
			_stack.push(N(w));
			continue;
		}
		if (input[i] == 'C') {
			int w = _stack.top();
			_stack.pop();
			int x = _stack.top();
			_stack.pop();
			_stack.push(C(w, x));
			continue;
		}
		if (input[i] == 'E') {
			int w = _stack.top();
			_stack.pop();
			int x = _stack.top();
			_stack.pop();
			_stack.push(E(w, x));
			continue;
		}
	}
	return _stack.top();
}

bool is_tautology() {
	for (p = 0; p < 2; p++) {
		for (q = 0; q < 2; q++) {
			for (r = 0; r < 2; r++) {
				for (s = 0; s < 2; s++) {
					for (t = 0; t < 2; t++) {
						if(!compute_express()) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

/*

(constructor)
Construct stack (public member function )
empty
Test whether container is empty (public member function )
size
Return size (public member function )
top
Access next element (public member function )
push
Insert element (public member function )
emplace 
Construct and insert element (public member function )
pop
Remove top element (public member function )
swap 
Swap contents (public member function )

*/

int main() {

	while (true) {
		memset(input, 0, 125);
		int in_len = scanf("%s", input);
		if (in_len == EOF) {
			return 0;
		}
		if (in_len >= 125) {
			cout << "not" << endl;
		}
		if (input[0] == '0') {
			return 0;
		}
		if (is_tautology()) {
			cout << "tautology" << endl;
		} else {
			cout 
			<<"not" << endl;
		}
	}
	return 0;
}