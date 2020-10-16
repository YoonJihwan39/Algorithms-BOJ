#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int N;
bool map[100][100];
int island[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    //섬을 구분
    int cnt = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && island[i][j] == 0){
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                island[i][j] = cnt;
                while(!q.empty()){
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++){
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];

                        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                        if(map[nx][ny] == 1 && island[nx][ny] == 0){
                            island[nx][ny] = cnt;
                            q.push(make_pair(nx, ny));
                        }
                    }

                }

                cnt++;
            }
        }
    }

    // 각 점에서 다리 놓기
    int result = 987654321;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0) continue;
            memset(visited, 0, sizeof(visited));
            int currIsland = island[i][j];
            queue<pair<int, pair<int, int>>> q;
            q.push({0, {i, j}});
            bool reached = 0;
            while(!q.empty()){
                int dist = q.front().first;
                int cx = q.front().second.first;
                int cy = q.front().second.second;
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                    if(map[nx][ny] == 0 && visited[nx][ny] == 0){
                        visited[nx][ny] = 1;
                        q.push({dist+1, {nx, ny}});
                    }
                    else if(map[nx][ny] == 1 && island[nx][ny] != currIsland){
                        reached = 1;
                        result = min(result, dist);
                        break;
                    }
                }
                if(reached) break;
            }
        }
    }
    cout << result;
    return 0;
}