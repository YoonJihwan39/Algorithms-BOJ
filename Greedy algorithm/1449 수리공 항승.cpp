#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    int position[N];
    int input;
    int tape_num = 0;
    int covered_poisition = 0;
    for(int i = 0; i < N; i++){
        cin >> position[i];
    }

    sort(position, position+N);

    for(int i = 0; i < N; i++){
        //누수된 위치에 테이프가 안 붙여져 있으면 새로 붙임.
        if(position[i] > covered_poisition){
            tape_num++;
            //누수된 위치를 포함하므로 L-1을 더해줘야 함.
            covered_poisition = position[i] + L - 1;
        }
    }

    cout << tape_num;
    return 0;
}