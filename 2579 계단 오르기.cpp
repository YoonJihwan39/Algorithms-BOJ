#include <iostream>
#include <algorithm>
using namespace std;

int stair[300];
int sum_point[2][300] = { 0, };
//sum_point[0]에는 1연속, sum_point[1]에는 2연속

int max_point(int H) {
	if (H == 0 || H == 1) {
		sum_point[0][0] = stair[0];
		sum_point[0][1] = stair[1];
		sum_point[1][1] = sum_point[0][0] + stair[1];
	}
	else {
		if (sum_point[0][H - 1] == 0 || sum_point[1][H - 1] == 0)
			max_point(H - 1);
		if (sum_point[0][H - 2] == 0 || sum_point[1][H - 2] == 0)
			max_point(H - 2);
		//바로 전 계단에서 올 경우 sum_point[0]에서만 가져와야함.
		sum_point[1][H] = sum_point[0][H - 1] + stair[H];
		//2계단 전에서 올 경우 둘 중 큰 값을 가져옴.
		sum_point[0][H] = max(sum_point[0][H - 2], sum_point[1][H - 2]) + stair[H];
	}
	//현재 계단에서 최대값 출력
	return max(sum_point[0][H], sum_point[1][H]);
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}
	cout << max_point(N - 1);
}
