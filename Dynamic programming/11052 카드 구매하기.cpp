#include<iostream>
using namespace std;

int N;
int P[1001];
int cache[1001];
// n은 현재 가지고 있는 카드의 수
// n에서 N-n개의 카드를 구입하기 위해 최대의 비용을 return
int DynamicProgramming (int n){
    int price = 0;
    if(n == N){
        return 0;
    }
    if(cache[n] != 0){
        return cache[n];
    }
    for(int i = 1; i <= N-n; i++){
        price = max(price, P[i] + DynamicProgramming(n+i));
    }
    cache[n] = price;
    return price;
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }
    cout << DynamicProgramming(0);
    return 0;
}