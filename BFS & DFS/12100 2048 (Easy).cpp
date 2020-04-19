#include <iostream>
using namespace std;

int N;
int map_input[20][20];
int map_result[20][20];
int result = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int map[20][20], int cnt){
    int result = 0;
    if(cnt == 5){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                result = max(result, map[y][x]);
            }
        }
        return result;
    }
    for(int i = 0; i < 4; i++){
        bool changed[20][20] = {0, };
        int map_copy[20][20];
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                map_copy[y][x] = map[y][x];
            }
        }
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                int y, x;
                //이동하는 방향에 따라 이동하는 순서 고려
                if(i == 0 || i == 2){
                    y = j;
                    x = k;
                }
                else if(i == 1){
                    y = j;
                    x = N - 1 - k;
                }
                else if(i == 3){
                    y = N - 1 - j;
                    x = k;
                }

                if(map_copy[y][x] != 0){
                    int ny = y, nx = x;
                    while(1){
                        ny += dy[i];
                        nx += dx[i];
                        //map을 벗어나면 그 전의 위치로 옮김
                        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
                            ny -= dy[i];
                            nx -= dx[i];
                            if(ny != y || nx != x){
                                map_copy[ny][nx] = map_copy[y][x];
                                map_copy[y][x] = 0;
                            }
                            break;
                        }
                        //0이 아닌 것을 만날 경우 같으면 합치고 다르면 그 전의 위치로 옮김
                        if(map_copy[ny][nx] != 0){
                            if(changed[ny][nx] == 0 && map_copy[ny][nx] == map_copy[y][x]){
                                map_copy[ny][nx] *= 2;
                                map_copy[y][x] = 0;
                                changed[ny][nx] = 1;
                            }
                            else {
                                ny -= dy[i];
                                nx -= dx[i];
                                if(ny != y || nx != x){
                                    map_copy[ny][nx] = map_copy[y][x];
                                    map_copy[y][x] = 0;
                                }
                            }
                            break;
                        }
                    }
                }
                
            }
        }
        result = max(result, dfs(map_copy, cnt+1));
    }
    return result;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map_input[i][j];
        }
    }
    cout << dfs(map_input, 0);
    return 0;
}