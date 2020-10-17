#include<iostream>
#include<string.h>
using namespace std;

int N;
long long cache[100][100];
int map[100][100];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

//x, y에서 목적지로 가는 경로 return
long long find_path(int x, int y){
    if(cache[x][y] != -1) return cache[x][y];
    if(map[x][y] == 0) return 0;

    long long result = 0;
    for(int i = 0; i < 2; i++){
        int nx = x + map[x][y] * dx[i];
        int ny = y + map[x][y] * dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        result += find_path(nx, ny);
    }
    cache[x][y] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N;
    cache[N-1][N-1] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    cout << find_path(0, 0);
    return 0;
}