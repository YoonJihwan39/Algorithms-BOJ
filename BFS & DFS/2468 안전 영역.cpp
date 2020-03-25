#include<iostream>
#include<cstring>
using namespace std;

int N;
int map[100][100];
bool visited[100][100];
int rain;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
            continue;
        }
        //방문한 적이 없고 rain보다 높이가 높다면 재귀호출
        if(visited[ny][nx] == 0 && map[ny][nx] > rain){
            dfs(nx, ny);
        }
    }
    return;
}

int main(){
    cin >> N;
    int highest = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            highest = max(highest, map[i][j]);
        }
    }
    int result = 1;
    for(int i = 1; i <= highest; i++){
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        rain = i;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(visited[y][x] == 0 && map[y][x] > rain){
                    cnt++;
                    dfs(x, y);
                }
            }
        }
        result = max(result, cnt);
    }
    cout << result;
    return 0;

}