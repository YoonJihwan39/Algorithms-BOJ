#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int M, N;
bool map[101][101];
int visited[4][101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


struct STATUS
{
    int x;
    int y;
    int dir;
    int dist;
};


int main(){
    cin >> M >> N;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
            for(int k = 0; k < 4; k++){
                visited[k][i][j] = 987654321;
            }
        }
    }
    int sx, sy, sdir;
    cin >> sx >> sy >> sdir;
    if(sdir == 2) sdir = 3;
    else if(sdir == 3) sdir = 2;
    else if(sdir == 4) sdir = 0;

    int fx, fy, fdir;
    cin >> fx >> fy >> fdir;
    if(fdir == 2) fdir = 3;
    else if(fdir == 3) fdir = 2;
    else if(fdir == 4) fdir = 0;

    queue<STATUS> q;
    q.push({sx, sy, sdir, 0});
    visited[sdir][sx][sy] = 0;

    int result = 987654321;

    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int cdir = q.front().dir;
        int cdist = q.front().dist;
        q.pop();

        if(cx == fx && cy == fy && cdir == fdir){
            result = min(result, cdist);
        }

        //진행하던 방향으로 이동
        for(int i = 1; i <= 3; i++){
            int nx = cx + i * dx[cdir];
            int ny = cy + i * dy[cdir];
            if(nx <= 0 || ny <= 0 || nx > M || ny > N || map[nx][ny]) break;

            if(cdist + 1 < visited[cdir][nx][ny]){
                visited[cdir][nx][ny] = cdist+1;
                q.push({nx, ny, cdir, cdist+1});
            }
        }
        
        //오른쪽으로 90도 회전
        int ndir = (cdir+1)%4;
        if(cdist + 1 < visited[ndir][cx][cy]){
            visited[ndir][cx][cy] = cdist+1;
            q.push({cx, cy, ndir, cdist+1});
        }
        
        //왼쪽으로 90도 회전
        ndir = (cdir == 0)? 3 : cdir-1;
        if(cdist + 1 < visited[ndir][cx][cy]){
            visited[ndir][cx][cy] = cdist + 1;
            q.push({cx, cy, ndir, cdist+1});
        }
    }
    cout << result;
    return 0;
}