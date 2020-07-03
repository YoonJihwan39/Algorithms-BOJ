#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int A[21][21];
int section[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 987654321;

int divide(int x, int y, int d1, int d2){
    vector<int> v (6, 0);
    memset(section, 0, sizeof(section));
    //section5부터 선정
    for(int i = 0; i <= d1; i++){
        section[x+i][y-i] = 5;
        section[x+d2+i][y+d2-i] = 5;
        if(d2 == 1 && i < d1){
            section[x+i+1][y-i] = 5;
        }
    }
    for(int i = 0; i <= d2; i++){
        section[x+i][y+i] = 5;
        section[x+d1+i][y-d1+i] = 5;
        if(d1 == 1 && i < d2){
            section[x+i+1][y+i] = 5;
        }
    }
    queue<pair<int, int>> q;
    section[x+1][y] = 5;
    q.push(make_pair(x+1, y));
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx <= 0 || ny <= 0 || nx > N || ny > N){
                continue;
            }
            if(section[nx][ny] == 0){
                section[nx][ny] = 5;
                q.push(make_pair(nx, ny));
            }
        }
    }

    //나머지 section 1, 2, 3, 4
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(section[r][c] == 5){
                v[5] += A[r][c];
                continue;
            }
            if(r < x + d1 && c <= y){
                v[1] += A[r][c];
            }
            else if(r <= x + d2 && c > y){
                v[2] += A[r][c];
            }
            else if(r >= x + d1 && c < y - d1 + d2){
                v[3] += A[r][c];
            }
            else{
                v[4] += A[r][c];
            }
        }
    }
    sort(v.begin(), v.end());
    return v[5] - v[1];


    
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }
    for(int d1 = 1; d1 <= N-2; d1++){
        for(int d2 = 1; d2 <= N - 1 - d1; d2++){
            for(int x = 1; x <= N - d1 - d2; x++){
                for(int y = d1 + 1; y <= N - d2; y++){
                    result = min(result, divide(x, y, d1, d2));
                }
            }
        }
    }
    cout << result;
    return 0;

}