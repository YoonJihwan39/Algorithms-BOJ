#include<iostream>
#include<cstring>
using namespace std;

int N;
int cache[1000001];

int num_binary(int N){
    if(cache[N] != -1){
        return cache[N];
    }
    //N-1에서 1을 붙일 수 있고 N-2에서 00을 붙일 수 있으므로 피보나치와 같다.
    int result = ((long long)num_binary(N-1) + (long long)num_binary(N-2)) % 15746;
    cache[N] = result;
    return result;
}


int main() {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cout << num_binary(N);
    return 0;
}