#include<iostream>
#include<string.h>
using namespace std;

int cache[21];
int N;

int fibo(int n){
    if(cache[n] != -1){
        return cache[n];
    }
    int result = fibo(n-2) + fibo(n-1);
    cache[n] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cache[0] = 0;
    cache[1] = 1;
    cin >> N;
    cout << fibo(N);
    return 0;
}