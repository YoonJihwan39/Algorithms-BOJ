#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int N;
vector<int> A;
int cache[1000][2]; // cache[i][j]는 i번째 숫자가 j가 0이면 왼쪽에서 작은 개수 1이면 오른쪽에서 작은 수들의 수열 중 가장 큰 것

int dp(int pos, int dir){
    if(cache[pos][dir] != -1){
        return cache[pos][dir];
    }
    int result = 0;
    if(dir == 0){
        for(int i = pos-1; i >= 0; i--){
            if(A[i] < A[pos]){
                result = max(result, 1+dp(i, 0));
            }
        }
    }
    else if(dir == 1){
        for(int i = pos+1; i < N; i++){
            if(A[i] < A[pos]){
                result = max(result, 1+dp(i, 1));
            }
        }
    }
    cache[pos][dir] = result;
    return result;
}

int main(){
    cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        A.push_back(input);
    }

    memset(cache, -1, sizeof(cache));
    int result = 0;
    for(int i = 0; i < N; i++){
        result = max(result, 1+dp(i, 0)+dp(i, 1));
    }
    cout << result;
    return 0;
}