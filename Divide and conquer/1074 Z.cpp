#include<iostream>
#include<cmath>
using namespace std;

int N, r, c;
int result = 0;
bool arrive = false;

void search(int size, int x, int y){
    //이미 도착했으면 return
    if(arrive){
        return;
    }
    //크기가 2x2면 탐색 시작
    
    if(size == 0){
        if(y == r && x == c){
            arrive = true;
        }
        return;
    }
    //크기가 2x2가 아니면 나누기
    int length = pow(2, size);
    int interval = length / 2;
    for(int i = y; i < y + length; i+=interval){
        for(int j = x; j < x + length; j+=interval){
            //나눌 범위 안에 존재한다면 나눔
            if(r <= i + interval - 1 && c <= j + interval - 1){
                search(size - 1, j, i);
                return;
            }
            //나눌 범위 안에 존재하지 않는다면 더해주기만하고 나누지 않음.
            else {
                result += pow(pow(2, size - 1), 2);
            }
        }
    }
    return;
}

int main(){
    cin >> N >> r >> c;

    search(N, 0, 0);
    cout << result;
    return 0;
}