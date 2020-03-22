#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[101][101];
int M, N, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> field;

int dfs(int x, int y){
    map[y][x] = 1;
    int area = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            continue;
        }
        if(map[ny][nx] == 0){
            area += dfs(nx, ny);
        }
    }
    return area;
}

int main(){
    cin >> M >> N >> K;
    int x1, y1, x2, y2;
    for(int i = 0; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                map[y][x] = 1;
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0){
                field.push_back(dfs(j, i));
            }
        }
    }
    sort(field.begin(), field.end());
    cout << field.size() << '\n';
    for(int i = 0; i < field.size(); i++){
        cout << field[i] << ' ';
    }
    return 0;
}