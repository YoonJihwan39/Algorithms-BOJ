#include<iostream>
using namespace std;

int N, M;
//북, 서, 남, 동
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int map[50][50];
int r, c, d;
int result = 0;

void robot(int y, int x){
    if(map[y][x] == 0){
        map[y][x] = -1;
        result++;
    }
    for(int i = 0; i < 4; i++){
        d = (d + 1) % 4;
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(map[ny][nx] == 0){
            robot(ny, nx);
            return;
        }
    }
    // 네 방향 모두 벽이거나 청소했을 경우 뒤에 벽이 있는지 확인
    int ny = y - dy[d];
    int nx = x - dx[d];
    if(map[ny][nx] != 1){
        robot(ny, nx);
        return;
    }
}

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;
    //dy, dx의 방향에 맞게 변환
    d = (4 - d) % 4; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    robot(r, c);
    cout << result;
    return 0;
}