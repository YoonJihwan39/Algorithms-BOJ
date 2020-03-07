#include<iostream>
#include<string>
using namespace std;

string image[64];
int N;

void compress(int begin_x, int begin_y, int end_x, int end_y){
    //크기가 1개짜리면 그냥 출력
    if(begin_x == end_x && begin_y == end_y){
        cout << image[begin_y][begin_x];
        return;
    }
    //하나로만 이루어져 있는지 확인
    bool same = true;
    char current = image[begin_y][begin_x];
    for(int i = begin_y; i <= end_y; i++){
        for(int j = begin_x; j <= end_x; j++){
            if(image[i][j] != current){
                same = false;
                break;
            }
        }
        if(same == false){
            break;
        }
    }
    //하나로만 이루어져 있다면 바로 출력
    if(same == true){
        cout << current;
        return;
    }

    //하나로만 이루어져 있지 않다면 나누기
    cout << '(';
    int length = end_x - begin_x + 1;
    int interval = length / 2;
    for(int i = begin_y; i <= end_y; i+=interval){
        for(int j = begin_x; j <= end_x; j+=interval){
            compress(j, i, j + interval - 1, i + interval - 1);
        }
    }
    cout << ')';
    return;
}

int main (){

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> image[i];
    }
    compress(0, 0, N-1, N-1);
    return 0;
}