#include <iostream>
using namespace std;

int cache[2][41] = {0, };
void fibonacci(int N, int& z, int& o) {
	int& ref0 = cache[0][N];
	int& ref1 = cache[1][N];
	if (N == 0) {
		z++;
		return;
	}
	else if (N == 1) {
		o++;
		return;
	}
	if (ref0 + ref1 == 0) {
		int a = 0, b = 0;
		fibonacci(N - 1, a, b);
		fibonacci(N - 2, a, b);
		z += a;
		o += b;
		ref0 = a;
		ref1 = b;
		return;
	}
	else {
		z += ref0;
		o += ref1;
		return;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int N;
		int zero = 0;
		int one = 0;
		cin >> N;
		fibonacci(N, zero, one);
		cout << zero << ' ' << one << endl;
	}
}
