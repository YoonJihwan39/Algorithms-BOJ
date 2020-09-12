#include<iostream>
#include<string.h>
using namespace std;

int N, K;
int cache[201][201];

// k개의 숫자를 더 뽑아서 n를 만들 수 있는 경우의 수를 return
int dp(int n, int k){
    if(cache[n][k] != -1){
        return cache[n][k];
    }
    int result = 0;
    //0부터 N까지 한개씩 뽑음
    for(int i = 0; i <= n; i++){
        result = (result + dp(n-i, k-1)) % 1000000000;
    }
    cache[n][k] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    for(int i = 0; i <= K; i++){
        cache[0][i] = 1;
    }
    for(int i = 1; i <= N; i++){
        cache[i][0] = 0; 
    }
    cout << dp(N, K);
    return 0;
}