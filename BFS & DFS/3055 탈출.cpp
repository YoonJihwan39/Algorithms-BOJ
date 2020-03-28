#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

struct Location {
    int x, y;
};

// 0이면 불, 1이면 고슴도치를  나타냄.
struct Object {
    bool hedgehog;
    int x, y, time;
};

int r, c;
string forest[50];
bool visited[50][50];
vector<Location> water;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(Location start){
    queue<Object> q;
    //queue에 물을 push
    for(int i = 0; i < water.size(); i++){
        q.push({0, water[i].x, water[i].y, 0});
    }
    //고슴도치의 위치를 push
    q.push({1, start.x, start.y, 0});
    visited[start.y][start.x] = 1;
    forest[start.y][start.x] = '.';

    while(!q.empty()){
        Object current = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            bool outside = nx < 0 || ny < 0 || nx >= c || ny >= r;
            if(outside) continue;
            if(current.hedgehog == 1){
                if(forest[ny][nx] == 'D') return current.time+1;
                if(forest[ny][nx] == '.' && visited[ny][nx] == 0){
                    q.push({1, nx, ny, current.time+1});
                    visited[ny][nx] = 1;
                }

            }
            if(current.hedgehog == 0){
                if(forest[ny][nx] == '.'){
                    forest[ny][nx] = '*';
                    q.push({0, nx, ny, 0});
                }
            } 
        }
    }
    return -1;

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Location start;
    water.clear();
    memset(visited, 0, sizeof(visited));
    cin >> r >> c;
    for(int height = 0; height < r; height++){
        cin >> forest[height];
        for(int width = 0; width < c; width++){
            if(forest[height][width] == '*'){
                water.push_back({width, height});
            }
            else if(forest[height][width] == 'S'){
                start = {width, height};
            }
        }
    }
    int result = bfs(start);
    if(result < 0){
        cout << "KAKTUS\n";
    }
    else {
        cout << result << '\n';
    }
    return 0;
}