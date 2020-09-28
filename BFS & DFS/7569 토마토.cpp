#include<iostream>
#include<queue>
using namespace std;

struct POS{
    int z;
    int x;
    int y;
    int day;
};

int M, N, H;
int box[100][100][100];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
queue<POS> ripe;

int main(){
    cin >> M >> N >> H;
    int unRipe = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    ripe.push({i, j, k, 0});
                }
                else if(box[i][j][k] == 0){
                    unRipe++;
                }
            }
        }
    }
    int result = 0;
    while(!ripe.empty()){
        POS curr = ripe.front();
        ripe.pop();
        result = max(result, curr.day);
        for(int i = 0; i < 6; i++){
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int nz = curr.z + dz[i];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;

            if(box[nz][nx][ny] == 0){
                box[nz][nx][ny] = 1;
                unRipe--;
                ripe.push({nz, nx, ny, curr.day+1});
            }
        }
    }
    if(unRipe){
        cout << -1;
    }
    else {
        cout << result;
    }
    return 0;
}