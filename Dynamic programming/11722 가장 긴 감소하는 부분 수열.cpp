#include<iostream>
using namespace std;

int N;
int A[1000];
int cache[1000];

int DP(int pos){
    if(pos == N-1){
        return 1;
    }
    if(cache[pos] != -1){
        return cache[pos];
    }
    int max = 0;
    for(int i = pos + 1; i < N; i++){
        if(A[i] >= A[pos]) continue;
        if(DP(i) > max){
            max = DP(i);
        }
    }
    cache[pos] = max + 1;
    return max + 1;
}

int main(){
    int result = -1;
    cin >> N;
    for(int i = 0; i < 1000; i++){
        cache[i] = -1;
    }
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        int tmp = DP(i);
        if(tmp > result) result = tmp;
    }
    cout << result << '\n';
    return 0;
}