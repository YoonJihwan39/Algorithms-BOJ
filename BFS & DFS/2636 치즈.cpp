#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

int N, M;
int map[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                cnt++;
            }
        }
    }
    int time = 1;
    queue<pair<int, int>> q;
    while(1){
        int deleteCheese = 0;
        q.push({0, 0});
        memset(visited, 0, sizeof(visited));

        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second;

            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(visited[nx][ny]) continue;
                if(map[nx][ny] == 1){
                    deleteCheese++;
                    map[nx][ny] = 0;
                    visited[nx][ny] = 1;
                }
                else if(map[nx][ny] == 0){
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        if(deleteCheese == cnt){
            cout << time << '\n' << deleteCheese << '\n';
            break;
        }
        else {
            cnt -= deleteCheese;
            time++;
        }
    }
    return 0;
}