#include<iostream>

using namespace std;

int main() {
    int N;
    int M;
    int sum;
    int result = 0;
    cin >> N;

    for(int i = 1; i <= N; i++){
        sum = i;
        M = i;
        while(M > 0){
            sum += (M % 10);
            M = M / 10;
        }
        if(sum == N){
            result = i;
            break;
        }
    }

    cout << result;
}