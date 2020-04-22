#include<iostream>
#include<queue>
using namespace std;

int N, M, x, y, K;
int map[20][20];
queue<int> order;
//주사위 윗 면이 0, 아랫 면이 5
int dice[6];

// 명령-1이 0이면 동쪽, 1이면 서쪽, 2라면 북쪽, 3이라면 남쪽
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void move_dice(int dir){
    //주사위 복사
    int copy[6];
    for(int i = 0; i < 6; i++){
        copy[i] = dice[i];
    }
    if(dir == 0){
        dice[0] = copy[3];
        dice[2] = copy[0];
        dice[3] = copy[5];
        dice[5] = copy[2];
    }
    else if(dir == 1){
        dice[0] = copy[2];
        dice[2] = copy[5];
        dice[3] = copy[0];
        dice[5] = copy[3];
    }
    else if(dir == 2){
        dice[0] = copy[4];
        dice[1] = copy[0];
        dice[4] = copy[5];
        dice[5] = copy[1];
    }
    else if(dir == 3){
        dice[0] = copy[1];
        dice[1] = copy[5];
        dice[4] = copy[0];
        dice[5] = copy[4];
    }
    return;
}

int main(){
    cin >> N >> M >> y >> x >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int input;
        cin >> input;
        order.push(input - 1);
    }

    while(!order.empty()){
        //가능한 명령일 때까지 skip
        int current_order;
        while(!order.empty()){
            current_order = order.front();
            order.pop();
            x += dx[current_order];
            y += dy[current_order];
            //이동할 곳이 지도 밖이면 되돌리기
            if(x < 0 || y < 0 || x >= M || y >= N){
                x -= dx[current_order];
                y -= dy[current_order];
            }
            //그렇지 않으면 실제 주사위 이동
            else {
                move_dice(current_order);
                cout << dice[0] << '\n';
                if(map[y][x] == 0){
                    map[y][x] = dice[5];
                }
                else {
                    dice[5] = map[y][x];
                    map[y][x] = 0;
                }
                break;
            }
        }
        
    }
    return 0;
}