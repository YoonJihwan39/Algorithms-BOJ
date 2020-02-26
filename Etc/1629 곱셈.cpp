#include<iostream>
using namespace std;

int main() {
    int A, B, C;

    cin >> A >> B >> C;

    long long result = 1;
    long long temp = A % C;
    //square and multiply algorithm 이용, 시간 log2
    while(B > 0){
        
        if(B % 2){
            result = (result * temp) % C;
        }
        B = B / 2;
        temp = (temp * temp) % C;

    }
    result = result % C;
    cout << result;
}