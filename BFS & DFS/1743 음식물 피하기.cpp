#include<iostream>
using namespace std;
int N, M, K;
int map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int y, int x){
    map[y][x] = 0;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        //상하좌우로 주변에 쓰레기가 있으면 재귀로 탐색
        if(ny <= 0 || nx <= 0 || ny > N || nx > M){
            continue;
        }
        if(map[ny][nx] == 1){
            cnt += dfs(ny, nx);
        }
    }
    return cnt;
}

int main(){
    cin >> N >> M >> K;
    int r, c;
    int result = 0;
    for(int i = 0; i < K; i++){
        cin >> r >> c;
        map[r][c] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(map[i][j] == 1){
                result = max(result, dfs(i, j));
            }
        }
    }
    cout << result;
    return 0;
}