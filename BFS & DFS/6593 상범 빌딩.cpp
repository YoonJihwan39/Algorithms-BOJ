#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int L, R, C;
string building[30][30];
bool visited[30][30][30];
int df[6] = {-1, 1, 0, 0, 0, 0};
int dr[6] = {0, 0, -1, 1, 0, 0};
int dc[6] = {0, 0, 0, 0, -1, 1};

struct Position
{
    int floor;
    int row;
    int col;
    int time;
};


int bfs(Position start){
    queue<Position> q;
    q.push(start);
    visited[start.floor][start.row][start.col] = 1;
    while(!q.empty()){
        Position current = q.front();
        q.pop();
        //6가지 방향으로 탐색
        for(int i = 0; i < 6; i++){
            int nf = current.floor + df[i];
            int nr = current.row + dr[i];
            int nc = current.col + dc[i];

            if(nf < 0 || nr < 0 || nc < 0 || nf >= L || nr >= R || nc >= C) continue;
            //다음 위치에 탈출구가 있다면 현재시간+1 반환
            if(building[nf][nr][nc] == 'E'){
                return current.time+1;
            }
            //방문한 적이 없는 길로 이동
            if(building[nf][nr][nc] == '.' && visited[nf][nr][nc] == 0){
                q.push({nf, nr, nc, current.time+1});
                visited[nf][nr][nc] = 1;
            }
        }
    }
    return -1;
}

int main(){
    while(1){
        memset(visited, 0, sizeof(visited));
        Position start;
        cin >> L >> R >> C;
        if(L + R + C == 0) {
            return 0;
        }
        char input;
        for(int floor = 0; floor < L; floor++){
            for(int row = 0; row < R; row++){
                cin >> building[floor][row];
                //시작점 찾기
                for(int col = 0; col < C; col++){
                    if(building[floor][row][col] == 'S'){
                        start = {floor, row, col, 0};
                    }
                }
            }
            cin.get();
        }
        int time = bfs(start);
        if(time < 0){
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << time <<" minute(s).\n";
        }
    }
    
}