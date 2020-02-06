#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_SIZE 25
int N;
char map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, int cnt) {
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
            continue;
        }
        else if(map[ny][nx] == '0' || visit[ny][nx] == 1){
            continue;
        }
        else {
            cnt = dfs(nx, ny, cnt+1);
        }
        
    }
    return cnt;
}

int main(){
    cin >> N;
    int size;
    vector<int> apart;
    for(int i = 0; i < N; i++){
        cin >> map[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == '0' || visit[i][j] == 1)
                continue;
            apart.push_back(dfs(j, i, 1));
        }
    }
    size = apart.size();
    cout << size << '\n';
    sort(apart.begin(), apart.end());
    for(int i = 0; i < size; i++){
        cout << apart[i] << '\n';
    }
    return 0;
}