#include<iostream>
#include<cstring>
using namespace std;

int K;
int C[501];
int cache[501][501];

int DP(int start, int end){
    if(cache[start][end] != -1){
        return cache[start][end];
    }
    if(start == end){
        return 0;
    }
    if(end - start + 1 == 2){
        cache[start][end] = C[start] + C[end];
        return cache[start][end];
    }

    int sum = 0;
    for(int i = start; i <= end; i++){
        sum += C[i];
    }
    int min = 987654321;
    for(int i = start; i <= end - 1; i++){
        int tmp = DP(start, i) + DP(i+1, end) + sum;
        if(tmp < min) min = tmp;
    }
    cache[start][end] = min;
    return min;
}

int main(){
    int T;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        memset(cache, -1, sizeof(cache));
        cin >> K;
        for(int i = 1; i <= K; i++){
            cin >> C[i];
        }
        cout << DP(1, K) << '\n';
    }
    return 0;
}