#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(){
    string str;
    cin >> str;
    int size = str.length();
    int N[size];
    int sum = 0, result = 0;
    for(int i = 0; i < size; i++){
        N[i] = str[i] - '0';
        sum += N[i];
    }
    sort(N, N+size, desc); //내림차순 정렬

    if(N[size-1] != 0 || sum % 3 != 0){ // 30의 배수이기 위해서는 끝자리 0 + 그외 자리수의 합은 3의 배수
        cout << -1;
    }
    else{
        for(int i = 0; i < str.length(); i++){
            cout << N[i];
        }
    }
    return 0;
}