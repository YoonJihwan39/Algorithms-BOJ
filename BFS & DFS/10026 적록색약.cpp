#include<iostream>
#include<string>
using namespace std;

int N;
string map[100];
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs_non_color_weakness (int x, int y){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
            continue;
        }
        //현재 위치의 색과 다음 위치의 색이 같으면 재귀호출
        if(visited[ny][nx] == 0 && map[y][x] == map[ny][nx]){
            dfs_non_color_weakness(nx, ny);
        }
    }
    return;
}

void dfs_color_weakness (int x, int y){
    visited[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
            continue;
        }
        //현재 위치의 색과 다음 위치의 색이 같거나, 둘다 파란색이 아니면 재귀호출
        if(visited[ny][nx] == 1 && (map[y][x] == map[ny][nx] || (map[y][x] != 'B' && map[ny][nx] != 'B'))){
            dfs_color_weakness(nx, ny);
        }
    }
    return;
}

int main(){
    cin >> N;
    int non_color_weakness = 0, color_weakness = 0;
    for(int i = 0; i < N; i++){
        cin >> map[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 0){
                non_color_weakness++;
                dfs_non_color_weakness(j, i);
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 1){
                color_weakness++;
                dfs_color_weakness(j, i);
            }
        }
    }
    cout << non_color_weakness << ' ' << color_weakness;
    return 0;
}
