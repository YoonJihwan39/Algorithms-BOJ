#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		char input[50];
		stack<char> stack;
		bool valid = true;
		cin >> input;
		int len = strlen(input);
		for (int j = 0; j < len; j++) {
			if (input[j] == '(') {
				stack.push('(');
			}
			else if (input[j] == ')') {
				//stack 안에 더이상 '(' 가 없다면 invalid
				if (stack.empty()) {
					valid = false;
					break;
				}
				else {
					stack.pop();
				}
			}
		}
		//stack 안에 ')'가 남아있다면 invalid
		if (valid && !stack.empty())
			valid = false;
		cout << ((valid) ? "YES" : "NO") << '\n';
	}
	return 0;
}
