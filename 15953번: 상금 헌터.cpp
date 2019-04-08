#include <iostream>
using namespace std;

int main()
{
	int first_contest[2][6] = {1, 3, 6, 10, 15, 21, 500, 300, 200, 50, 30, 10 };
	int second_contest[2][5] = {1, 3, 7, 15, 31, 512, 256, 128, 64, 32 };
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int first, second, sum = 0;
		cin >> first;
		cin >> second;
		if (first != 0) {
			for (int j = 0; j < 6; j++) {
				if ((first - first_contest[0][j]) <= 0) {
					sum += first_contest[1][j];
					break;
				}
			}
		}
		if (second != 0) {
			for (int j = 0; j < 5; j++) {
				if ((second - second_contest[0][j]) <= 0) {
					sum += second_contest[1][j];
					break;
				}
			}
		}
		cout << sum * 10000 << '\n';
	}
	return 0;
}
