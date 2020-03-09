#include<iostream>
#include<cstring>
using namespace std;

int N;
long long cache[91][2];

long long primary_number(int N, int digit){

    long long result;

    if(cache[N][digit] != -1){
        return cache[N][digit]; 
    }

    if(digit == 0){
        result = primary_number(N-1 , 0) + primary_number(N-1, 1);
    }
    else {
        result = primary_number(N-1 , 0);
    }

    cache[N][digit] = result;
    return result;
}

int main() {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cache[1][0] = 0;
    cache[1][1] = 1;
    cout << primary_number(N, 0) + primary_number(N, 1);
    return 0;
}