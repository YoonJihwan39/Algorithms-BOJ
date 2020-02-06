#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 1000
int N, M;
int map[MAX_SIZE][MAX_SIZE];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs() {
    int day = 0;
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1){
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().first.first;
        int cnt = q.front().second;

        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N){
            continue;
            }
            else if(map[ny][nx] == 0){
                map[ny][nx] = 1;
                q.push(make_pair(make_pair(ny, nx), cnt+1));
                day = cnt+1;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                day = -1;
            }
        }
    }
    return day;
}

int main(){
    cin >> M >> N;
    int day = 0;
    int temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    cout << bfs();
    return 0;
}