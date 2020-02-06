#include <iostream>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    int count = 0;
    int num = 0;
    cin >> N >> K;

    int value[N];

    for(int i = N-1; i >= 0; i--){
        cin >> value[i];
    }
    
    
    while(count < K){
        for(int i = 0; i < N; i++){
            if(value[i] <= K - count){
                count += value[i];
                num++;
                break;
            }
        }
    }

    cout << num;

    return 0;

}