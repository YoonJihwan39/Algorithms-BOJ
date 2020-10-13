#include<iostream>
#include<string.h>
using namespace std;

int N, M;
int map[1000][1000];
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int cache[1000][1000]; // 해당 점에서 시작하여 최대로 가질 수 있는 사탕 개수

int dfs(int r, int c){
    if(cache[r][c] != -1){
        return cache[r][c];
    }
    int result = 0;
    for(int i = 0; i < 3; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];

        if(nr >= N || nc >= M){
            continue;
        }
        result = max(result, map[r][c] + dfs(nr, nc));
    }
    cache[r][c] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    cache[N-1][M-1] = map[N-1][M-1];

    cout << dfs(0, 0);
    return 0;

}