//참고: http://kks227.blog.me/220777103650
#include<iostream>
#include<cstring>
using namespace std;

int N;
int cache[101][10];
//길이가 N이고 첫 자리수가 digit인 계단수 return 
int stair_num (int N, int digit){
    int result;
    if(N == 1){
        return 1;
    }
    if(cache[N][digit] != -1){
        return cache[N][digit];
    }
    if(digit == 0){
        result = stair_num(N-1, 1);
    }
    else if(digit == 9){
        result = stair_num(N-1, 8);
    }
    else {
        result = stair_num(N-1, digit-1)+ stair_num(N-1, digit+1);
    }
    result = result % 1000000000;
    cache[N][digit] = result;
    return result;
}

int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    int result = 0;
    for(int i = 1; i <= 9; i++){
        result = (result + stair_num(N, i)) % 1000000000;
    }
    cout << result;
    return 0;
}