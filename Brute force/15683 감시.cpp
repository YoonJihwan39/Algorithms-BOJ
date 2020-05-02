#include<iostream>
#include<vector>
using namespace std;

struct CCTV {
    int type;
    int y, x;
};

int N, M;
vector<CCTV> v;
int result = 987654321;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void copy_map(int original[8][8], int copy[8][8]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            copy[i][j] = original[i][j];
        }
    }
    return;
}

void find_blind_spot(int nth, int map[8][8]){
    if(nth == v.size()){
        int temp_result = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0){
                    temp_result++;
                }
            }
        }
        result = min(result, temp_result);
        return;
    }

    int copy[8][8];
    // CCTV 1일 때 한방향으로 4번 확인
    if(v[nth].type == 1){
        for(int i = 0; i < 4; i++){
            copy_map(map, copy);
            int ny = v[nth].y + dy[i];
            int nx = v[nth].x + dx[i];
            while(ny >= 0 && nx >= 0 && ny < N && nx < M){
                if(copy[ny][nx] == 0){
                    copy[ny][nx] = -1;
                }
                else if(copy[ny][nx] == 6){
                    break;
                }
                ny += dy[i];
                nx += dx[i];
            }
            find_blind_spot(nth+1, copy);
        }
    }
    // CCTV 2일 때 양방향으로 2번 확인
    else if(v[nth].type == 2){
        for(int i = 0; i < 2; i++){
            copy_map(map, copy);
            int ny1 = v[nth].y + dy[i];
            int nx1 = v[nth].x + dx[i];
            int ny2 = v[nth].y + dy[i+2];
            int nx2 = v[nth].x + dx[i+2];
            while(ny1 >= 0 && nx1 >= 0 && ny1 < N && nx1 < M){
                if(copy[ny1][nx1] == 0){
                    copy[ny1][nx1] = -1;
                }
                else if(copy[ny1][nx1] == 6){
                    break;
                }
                ny1 += dy[i];
                nx1 += dx[i];
            }
            while(ny2 >= 0 && nx2 >= 0 && ny2 < N && nx2 < M){
                if(copy[ny2][nx2] == 0){
                    copy[ny2][nx2] = -1;
                }
                else if(copy[ny2][nx2] == 6){
                    break;
                }
                ny2 += dy[i+2];
                nx2 += dx[i+2];
            }
            find_blind_spot(nth+1, copy);
        }
    }
    // CCTV 3일 때 직각방향으로 4번 확인
    else if(v[nth].type == 3){
        for(int i = 0; i < 4; i++){
            copy_map(map, copy);
            int ny1 = v[nth].y + dy[i];
            int nx1 = v[nth].x + dx[i];
            int ny2 = v[nth].y + dy[(i+1)%4];
            int nx2 = v[nth].x + dx[(i+1)%4];
            while(ny1 >= 0 && nx1 >= 0 && ny1 < N && nx1 < M){
                if(copy[ny1][nx1] == 0){
                    copy[ny1][nx1] = -1;
                }
                else if(copy[ny1][nx1] == 6){
                    break;
                }
                ny1 += dy[i];
                nx1 += dx[i];
            }
            while(ny2 >= 0 && nx2 >= 0 && ny2 < N && nx2 < M){
                if(copy[ny2][nx2] == 0){
                    copy[ny2][nx2] = -1;
                }
                else if(copy[ny2][nx2] == 6){
                    break;
                }
                ny2 += dy[(i+1)%4];
                nx2 += dx[(i+1)%4];
            }
            find_blind_spot(nth+1, copy);
        }
    }
    // CCTV 4일 때 세방향으로 4번 확인
    else if(v[nth].type == 4){
        for(int i = 0; i < 4; i++){
            copy_map(map, copy);
            int ny1 = v[nth].y + dy[i];
            int nx1 = v[nth].x + dx[i];
            int ny2 = v[nth].y + dy[(i+1)%4];
            int nx2 = v[nth].x + dx[(i+1)%4];
            int ny3 = v[nth].y + dy[(i+2)%4];
            int nx3 = v[nth].x + dx[(i+2)%4];
            while(ny1 >= 0 && nx1 >= 0 && ny1 < N && nx1 < M){
                if(copy[ny1][nx1] == 0){
                    copy[ny1][nx1] = -1;
                }
                else if(copy[ny1][nx1] == 6){
                    break;
                }
                ny1 += dy[i];
                nx1 += dx[i];
            }
            while(ny2 >= 0 && nx2 >= 0 && ny2 < N && nx2 < M){
                if(copy[ny2][nx2] == 0){
                    copy[ny2][nx2] = -1;
                }
                else if(copy[ny2][nx2] == 6){
                    break;
                }
                ny2 += dy[(i+1)%4];
                nx2 += dx[(i+1)%4];
            }
            while(ny3 >= 0 && nx3 >= 0 && ny3 < N && nx3 < M){
                if(copy[ny3][nx3] == 0){
                    copy[ny3][nx3] = -1;
                }
                else if(copy[ny3][nx3] == 6){
                    break;
                }
                ny3 += dy[(i+2)%4];
                nx3 += dx[(i+2)%4];
            }
            find_blind_spot(nth+1, copy);
        }
    }
    // CCTV 5일 때 네방향으로 1번 확인
    else if(v[nth].type == 5){
        copy_map(map, copy);
        for(int i = 0; i < 4; i++){
            int ny = v[nth].y + dy[i];
            int nx = v[nth].x + dx[i];
            while(ny >= 0 && nx >= 0 && ny < N && nx < M){
                if(copy[ny][nx] == 0){
                    copy[ny][nx] = -1;
                }
                else if(copy[ny][nx] == 6){
                    break;
                }
                ny += dy[i];
                nx += dx[i];
            }
        }
        find_blind_spot(nth+1, copy);
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int map[8][8];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5){
                v.push_back({map[i][j], i, j});
            }
        }
    }
    find_blind_spot(0, map);
    cout << result;
    return 0;
}