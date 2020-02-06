#include<iostream>
using namespace std;
#define MAX_SIZE 50
int T, M, N, K;
int map[MAX_SIZE][MAX_SIZE];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y){
    map[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N){
            continue;
        }
        else if(map[ny][nx] == 1){
            dfs(nx, ny);
        }
    }
    return;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++){
        int cnt = 0;
        cin >> M >> N >> K;
        for(int j = 0; j < K; j++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        for(int a = 0; a < N; a++){
            for(int b = 0; b < M; b++){
                if(map[a][b] == 1){
                    dfs(b, a);
                    cnt++;
                    map[a][b] = 0;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
