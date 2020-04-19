#include <iostream>
#include <queue>
using namespace std;

int N, M;
string map[10];
bool visited[10][10][10][10];
int R_y, R_x;
int B_y, B_x;
int O_y, O_x;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Situation
{
    int R_pos_y, R_pos_x;
    int B_pos_y, B_pos_x;
    int cnt;
};


int bfs(){
    Situation start = {R_y, R_x, B_y, B_x, 0};
    visited[R_y][R_x][B_y][B_x] = 1;
    queue<Situation> q;
    q.push(start);
    while(!q.empty()){
        Situation current = q.front();
        q.pop();
        if(current.B_pos_y == O_y && current.B_pos_x == O_x){
            continue;
        }
        else if(current.R_pos_y == O_y && current.R_pos_x == O_x){
            return current.cnt;
        }
        if(current.cnt >= 10){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int rny = current.R_pos_y;
            int rnx = current.R_pos_x;
            int bny = current.B_pos_y;
            int bnx = current.B_pos_x;
            bool R_fall = 0, B_fall = 0;
            bool R_stuck = 0, B_stuck = 0;

            while(!(R_stuck && B_stuck)){
                int temp_rny = rny;
                int temp_rnx = rnx;
                int temp_bny = bny;
                int temp_bnx = bnx;
                if(!R_stuck){
                    temp_rny += dy[i];
                    temp_rnx += dx[i];
                }
                if(!B_stuck){
                    temp_bny += dy[i];
                    temp_bnx += dx[i];
                }
                if(map[temp_rny][temp_rnx] == 'O'){
                    R_fall = 1;
                    R_stuck = 1;
                }
                if(map[temp_bny][temp_bnx] == 'O'){
                    B_fall = 1;
                    B_stuck = 1;
                    break;
                }
                if(map[temp_rny][temp_rnx] == '#'){
                    temp_rny = rny;
                    temp_rnx = rnx;
                    R_stuck = 1;
                }
                if(map[temp_bny][temp_bnx] == '#'){
                    temp_bny = bny;
                    temp_bnx = bnx;
                    B_stuck = 1;
                }

                if(R_fall || temp_rny != temp_bny || temp_rnx != temp_bnx){
                    rny = temp_rny;
                    rnx = temp_rnx;
                    bny = temp_bny;
                    bnx = temp_bnx;
                }
                else if(temp_rny == temp_bny && temp_rnx == temp_bnx){
                    B_stuck = 1;
                    R_stuck = 1;
                }
            }
            if(B_fall){
                continue;
            }
            else if(R_fall){
                return current.cnt+1;
            }
            else if(visited[rny][rnx][bny][bnx] == 0){
                q.push({rny, rnx, bny, bnx, current.cnt+1});
                visited[rny][rnx][bny][bnx] = 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> map[i];
        for(int j = 0; j < M; j++){
            if(map[i][j] == 'R'){
                R_y = i;
                R_x = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B'){
                B_y = i;
                B_x = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'O'){
                O_y = i;
                O_x = j;
            }
        }
    }
    cout << bfs();
    return 0;

}