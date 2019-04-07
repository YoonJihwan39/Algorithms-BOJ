//스택 구현은 하지 않고 c++에서 제공하는 stack 을 사용했습니다.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, X;
	string input;
	stack<int> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push") {
			cin >> X;
			S.push(X);
		}
		else if (input == "pop") {
			if (S.empty())
				cout << -1 << '\n';
			else {
				cout << S.top() << '\n';
				S.pop();
			}
		}
		else if (input == "size") {
			cout << S.size() << '\n';
		}
		else if (input == "empty") {
			cout << S.empty() << '\n';
		}
		else if (input == "top") {
			if (S.empty())
				cout << -1 << '\n';
			else
				cout << S.top() << '\n';
		}
	}
	return 0;
}
