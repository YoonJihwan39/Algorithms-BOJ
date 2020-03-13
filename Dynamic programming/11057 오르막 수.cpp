#include<iostream>
#include<cstring>
using namespace std;

int N;
int cache[1001][10];
//길이가 N이고 첫 자리수가 digit인 오르막수 return 
int ascent_num (int N, int digit){
    int result = 0;
    if(N == 1){
        return 1;
    }
    if(cache[N][digit] != -1){
        return cache[N][digit];
    }
    for(int i = digit; i <= 9; i++){
        result = (result + ascent_num(N-1, i)) % 10007;
    }
    cache[N][digit] = result;
    return result;
}

int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    int result = 0;
    for(int i = 0; i <= 9; i++){
        result = (result + ascent_num(N, i)) % 10007;
    }
    cout << result;
    return 0;
}