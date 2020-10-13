#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int N, M;
char map[50][50];
bool visited[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct STATUS
{
    int x;
    int y;
    int dist;
};


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 'W'){
                continue;
            }
            memset(visited, 0, sizeof(visited));
            visited[i][j] = 1;
            queue<STATUS> q;
            q.push({i, j, 0});
            while(!q.empty()){
                STATUS curr = q.front();
                q.pop();
                if(curr.dist > result) result = curr.dist;
                for(int i = 0; i < 4; i++){
                    int nx = curr.x + dx[i];
                    int ny = curr.y + dy[i];

                    if(ny < 0 || nx < 0 || nx >= N || ny >= M){
                        continue;
                    }
                    if(map[nx][ny] == 'L' && visited[nx][ny] == 0){
                        visited[nx][ny] = 1;
                        q.push({nx, ny, curr.dist+1});
                    }
                }
            }
        }
    }
    cout << result;
    return 0;
}