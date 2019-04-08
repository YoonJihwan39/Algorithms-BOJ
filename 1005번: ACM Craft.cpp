#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ACM_craft(int object, int num_of_building, int *build_time, int *sum_time, int **requirements) {
	int time = 0;
	//만약 필요한 건물이 없다면 바로 build_time만 추가
	if (requirements[object][0] == 0) {
		sum_time[object] = build_time[object];
	}
	//만약 이전에 구한 값이 없다면 
	else if (sum_time[object] == -1) {
		for (int i = 1; i <= requirements[object][0]; i++) {
			int require = requirements[object][i];
			//필요한 건물의 소요시간 알아내기
			if (sum_time[require] == -1)
				ACM_craft(require, num_of_building, build_time, sum_time, requirements);
			//소요시간 중에 큰 시간만 필요함
			time = max(time, sum_time[require]);
		}
		time += build_time[object];
		sum_time[object] = time;
	}
	return sum_time[object];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, K, object;
		cin >> N;
		cin >> K;
		int *build_time = new int[N+1]{ 0, };
		int *sum_time = new int[N + 1];
		int **requirements = new int*[N+1];

		for (int j = 0; j < N + 1; j++)
			sum_time[j] = -1;

		for (int j = 0; j <= N; j++) {
			requirements[j] = new int[N + 1]{ 0, };
		}
		for (int j = 1; j <= N; j++) {
			cin >> build_time[j];
		}
		for (int j = 0; j < K; j++) {
			int requirement, building;
			cin >> requirement;
			cin >> building;
			int len = requirements[building][0] + 1;
			requirements[building][len] = requirement;
			requirements[building][0]++;
		}
		cin >> object;
		//입력끝

		cout << ACM_craft(object, N, build_time, sum_time, requirements) << '\n';

		//메모리 해제
		delete[] build_time;
		delete[] sum_time;
		for (int j = 0; j <= N; ++j) {
			delete[] requirements[j];
		}
	}
	return 0;
}
