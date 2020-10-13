#include<iostream>
#include<algorithm>
using namespace std;

int dice[10];
int map[33];

int move(int start, int dist){
    int dest = start;
    if(start == 5) {
        dest = 22;
        dist--;
    }
    else if(start == 10) {
        dest = 25;
        dist--;
    }
    else if(start == 15) {
        dest = 27;
        dist--;
    }

    while(dist > 0){
        if(dest == 21) break;

        
        if(dest == 24 || dest == 26 || dest == 29) dest = 30;
        else if(dest == 32) dest = 20;
        else dest++;
        dist--;
    }
    return dest;
}

int simulation(int nth, int piece[4]){
    int result = 0;
    if(nth == 10) return 0;
    int copyPiece[4];
    copy(piece, piece + 4, copyPiece);
    for(int i = 0; i < 4; i++){
        //만약 '도착'에 있다면 해당 말은 움직일 수 없음
        if(copyPiece[i] == 21) continue;

        int nextPos = move(copyPiece[i], dice[nth]);
        //이동할 위치에 다른 말이 있는지 확인
        bool possible = 1;
        for(int j = 0; j < 4; j++){
            if(i == j) continue;
            if(nextPos != 21 && nextPos == copyPiece[j]){
                possible = 0;
                break;
            }
        }

        if(possible){
            copyPiece[i] = nextPos;
            result = max(result, ((nextPos != 21) ? map[nextPos] : 0) + simulation(nth+1, copyPiece));
            copyPiece[i] = piece[i];
        }
    }
    return result;
}

int main(){
    for(int i = 0; i <= 20; i++){
        map[i] = 2 * i;
    }
    map[21] = -1;
    map[22] = 13, map[23] = 16, map[24] = 19, map[25] = 22, map[26] = 24, map[27] = 28, map[28] = 27, map[29] = 26, map[30] = 25, map[31] = 30, map[32] = 35;
    for(int i = 0; i < 10; i++){
        cin >> dice[i];
    }
    int temp[4] = {0, 0, 0, 0};
    cout << simulation(0, temp);
    return 0;
}