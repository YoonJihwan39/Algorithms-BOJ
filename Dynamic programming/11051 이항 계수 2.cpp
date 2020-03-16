#include<iostream>
#include<cstring>
using namespace std;

int N, K;
int cache[1001][1001];

int binomial_coefficient(int n, int k){
    if(k == 0 || n == k){
        return 1;
    }
    if(cache[n][k] != -1){
        return cache[n][k];
    }
    if(cache[n][n-k] != -1){
        return cache[n][n-k];
    }
    int result;
    result = (binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k)) % 10007;
    cache[n][k] = cache[n][n-k] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    cout << binomial_coefficient(N, K);
    return 0;
}