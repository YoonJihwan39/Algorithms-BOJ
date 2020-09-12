#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int w, h;
int map[50][50];
bool visited[50][50];
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, 1, 1, -1, -1};

void bfs(int x, int y){
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int cx = current.first + dx[i];
            int cy = current.second + dy[i];

            if(cx < 0 || cy < 0 || cx >= h || cy >= w || map[cx][cy] == 0 || visited[cx][cy] == 1){
                continue;
            }

            visited[cx][cy] = 1;
            q.push(make_pair(cx, cy));
        }
    }
    return;
}

int main(){
    while(1){
        memset(visited, 0, sizeof(visited));
        cin >> w >> h;
        if(w + h == 0){
            break;
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i][j];
            }
        }
        int result = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] == 0 || visited[i][j]){
                    continue;
                }
                result++;
                bfs(i, j);
            }
        }
        cout << result << '\n';
    }
    return 0;
}