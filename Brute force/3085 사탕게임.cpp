#include<iostream>
#include<string>
#include<set>
using namespace std;

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

string map[50];

int checkLength(int y, int x, int ny, int nx) {
    int result = 1;
    int height = 1;
    int width = 1;
    
    //swap
    char temp = map[y][x];
    map[y][x] = map[ny][nx];
    map[ny][nx] = temp;

    char target = map[y][x];

    for(int i = y-1; i >= 0; i--){ //세로길이 윗부분
        if(map[i][x] != target){
            break;
        }
        height++;
    }
    for(int i = y+1; i < N; i++){ //세로길이 아래부분
        if(map[i][x] != target){
            break;
        }
        height++;
    }
    for(int i = x-1; i >= 0; i--){ //가로길이 왼쪽부분
        if(map[y][i] != target){
            break;
        }
        width++;
    }
    for(int i = x+1; i < N; i++){ //가로길이 오른쪽부분
        if(map[y][i] != target){
            break;
        }
        width++;
    }

    //다시 원래대로 swap
    temp = map[y][x];
    map[y][x] = map[ny][nx];
    map[ny][nx] = temp;

    if(width >= height){
        return width;
    }
    else {
        return height;
    }
}

int main() {

    int max_candy = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> map[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //각 점을 기준으로 상하좌우 바꿈(같은 것끼리도 바꿔야 안 바꾸는 경우도 포함됨)
            char current_candy = map[i][j];
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N){
                    continue;
                }
                int temp = checkLength(i, j, ny, nx);
                if(temp > max_candy){
                    max_candy = temp;
                }
            }
            
        }
    }
    cout << max_candy;
}