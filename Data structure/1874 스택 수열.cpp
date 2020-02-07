#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	int index = 0;
	cin >> n;
	int *sequence = new int[n]; //수열 길이만큼 동적할당
	queue<char> output; //출력값 저장을 위한 Queue
	stack<int> S;//Stack

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	} 
	//입력 끝

	for (int i = 1; i <= n + 1; i++) {
		//S가 비어있지 않고 맨 앞의 값이 Sequence 앞 값과 같으면 Pop
		while (!S.empty() && sequence[index] == S.top()) {
			S.pop();
			output.push('-');
			index++;
		}
		if (i != n + 1) {
			S.push(i);
			output.push('+');
		}
	}
	if (index != n)
		cout << "NO";
	else {
	while (!output.empty()) {
		cout << output.front() << '\n';
		output.pop();
		}
	}
	delete[] sequence;
	return 0;
}
