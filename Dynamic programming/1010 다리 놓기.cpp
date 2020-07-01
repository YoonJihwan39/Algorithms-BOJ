#include<iostream>
#include<string.h>
using namespace std;

int T, N, M;
int cache[31][31];

// 서쪽의 n번째 사이트에서 m번째 사이트로 다리를 놓을때 경우의 수를 return
int DP(int n, int m){
    if(n == N){
        return 1;
    }
    if(m == M){
        return -9999;
    }
    if(cache[n][m] != -1){
        return cache[n][m];
    }
    int count = 0;
    for(int i = m+1; i <= M; i++){
        int temp = DP(n+1, i);
        if(temp >= 0){
            count += temp;
        }
    }
    cache[n][m] = count;
    return count;
}

int main(){
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        memset(cache, -1, sizeof(cache));
        cin >> N >> M;
        cout << DP(0, 0) << '\n';
    }
    return 0;
}