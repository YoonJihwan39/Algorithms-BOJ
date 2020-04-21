#include<iostream>
using namespace std;

int N, B, C;
int array[1000000];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }
    cin >> B >> C;
    // 총 감독관은 이미 있다고 가정
    long long cnt = N;
    for(int i = 0; i < N; i++){
        array[i] -= B;
        if(array[i] <= 0){
            continue;
        }
        else {
            cnt = cnt + (array[i] / C);
            if(array[i] % C != 0){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}