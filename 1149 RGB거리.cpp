#include <iostream>
#include <algorithm>

using namespace std;

int total_cost[3][1000] = { 0, };
int cost[3][1000];

int Min_cost(int n) {
	if (n == 0) {
		total_cost[0][0] = cost[0][0];
		total_cost[1][0] = cost[1][0];
		total_cost[2][0] = cost[2][0];
	}
	else {
		Min_cost(n - 1);
		total_cost[0][n] = cost[0][n] + min(total_cost[1][n - 1], total_cost[2][n - 1]);
		total_cost[1][n] = cost[1][n] + min(total_cost[0][n - 1], total_cost[2][n - 1]);
		total_cost[2][n] = cost[2][n] + min(total_cost[0][n - 1], total_cost[1][n - 1]);
	}
	return min(total_cost[0][n], min(total_cost[1][n], total_cost[2][n]));
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
	}
	cout << Min_cost(N-1);
	return 0;
}
