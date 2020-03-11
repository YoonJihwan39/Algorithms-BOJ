#include<iostream>
#include<cstring>
using namespace std;

int cache[1001];
int n;

int num_of_way (int n){
    if(cache[n] != -1){
        return cache[n];
    }
    //2번째 전 단계에서 가로로 된 타일로 채우기 + 1번째 전 단계에서 세로로 된 타일로 채우기
    //피보나치와 같음.
    int result = (num_of_way(n-1) + num_of_way(n-2)) % 10007;
    cache[n] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cin >> n;
    cout << num_of_way(n);
    return 0;
}

