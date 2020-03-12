#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int N;
int cache[100001];

// 제곱 근의 합으로 만들 수 있는 N 중에서 가장 작은 수를 사용한 개수 return
int sum_of_square(int N){
    if(N == 0){
        return 0;
    }
    if(N < 0){
        return 100001;
    }
    if(cache[N] != -1){
        return cache[N];
    }
    int result = 100001;
    //11의 제곱근보다 작은 수를 사용하여 재귀
    for(int i = 1; i <= sqrt(N); i++){
        result = min(result, 1 + sum_of_square(N - pow(i, 2)));
    }
    cache[N] = result;
    return result;
}
int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << sum_of_square(N);
    return 0;
}