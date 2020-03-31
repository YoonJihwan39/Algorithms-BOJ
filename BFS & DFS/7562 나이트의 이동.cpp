#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[300][300];
int l, start_x, start_y, destination_x, destination_y;

struct Situation{
    int x, y, time;
};

int dfs(){
    queue<Situation> q;
    q.push({start_x, start_y, 0});
    visited[start_y][start_x] = 1;
    while(!q.empty()){
        Situation current = q.front();
        if(current.x == destination_x && current.y == destination_y){
            return current.time;
        }
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if(visited[ny][nx] == 0){
                q.push({nx, ny, current.time+1});
                visited[ny][nx] = 1;
            }
        }
    }
    return -1;
}

int main(){
    int T;
    
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        memset(visited, 0, sizeof(visited));
        cin >> l;
        cin >> start_x >> start_y >> destination_x >> destination_y;
        cout << dfs() << '\n';
    }
    return 0;
}