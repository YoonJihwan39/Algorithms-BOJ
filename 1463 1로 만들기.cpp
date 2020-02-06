#include <iostream>
#include <algorithm>
using namespace std;

int min_one[1000001] = { 0, };

int make_one(int n) {
	int minnum = 999999;
	if (n == 1) {
		min_one[1] = 0;
		return 0;
	}
	if (n % 3 == 0) {
		if(min_one[n/3] == 0)
			make_one(n / 3);
		minnum = min_one[n / 3] + 1;
	}
	if (n % 2 == 0) {
		if (min_one[n / 2] == 0)
			make_one(n / 2);
		minnum = min(minnum, min_one[n / 2] + 1);
	}
	if (min_one[n - 1] == 0)
		make_one(n - 1);
	minnum = min(minnum, min_one[n - 1] + 1);

	min_one[n] = minnum;
	return minnum;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << make_one(N);
}
