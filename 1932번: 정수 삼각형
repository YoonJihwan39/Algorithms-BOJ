#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int triangle[500][500];
int sum[500][500];

int max_route(int y, int x) {
	if (y == 0) {
		sum[0][0] = triangle[0][0];
	}
	else if (x == 0) {
		if(sum[y-1][x] == -1)
			max_route(y - 1, x);
		sum[y][x] = sum[y - 1][x] + triangle[y][x];
	}
	else if (x == y) {
		if (sum[y - 1][x - 1] == -1)
			max_route(y - 1, x - 1);
		sum[y][x] = sum[y - 1][x - 1] + triangle[y][x];
	}
	else {
		if (sum[y - 1][x] == -1)
			max_route(y - 1, x);
		if (sum[y - 1][x - 1] == -1)
			max_route(y - 1, x - 1);
		sum[y][x] = triangle[y][x] + max(sum[y - 1][x], sum[y - 1][x - 1]);
	}
	return sum[y][x];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(sum, -1, sizeof(sum));
	int N;
	int maxR = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		maxR = max(maxR, max_route(N - 1, i));
	}
	cout << maxR;
	return 0;
}
