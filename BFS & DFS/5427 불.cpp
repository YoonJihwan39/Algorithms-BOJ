#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

struct Location {
    int x, y;
};

// 0이면 불, 1이면 상근이를  나타냄.
struct Object {
    bool human;
    int x, y, time;
};

int test_case, w, h;
string building[1000];
bool visited[1000][1000];
vector<Location> fire;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(Location start){
    queue<Object> q;
    //queue에 불을 push
    for(int i = 0; i < fire.size(); i++){
        q.push({0, fire[i].x, fire[i].y, 0});
    }
    //상근이의 위치를 push
    q.push({1, start.x, start.y, 0});
    visited[start.y][start.x] = 1;
    building[start.y][start.x] = '.';

    while(!q.empty()){
        Object current = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            bool outside = nx < 0 || ny < 0 || nx >= w || ny >= h;
            if(current.human == 1){
                if(outside) return current.time+1;
                if(building[ny][nx] == '.' && visited[ny][nx] == 0){
                    q.push({1, nx, ny, current.time+1});
                    visited[ny][nx] = 1;
                }

            }
            if(current.human == 0){
                if(outside) continue;
                if(building[ny][nx] == '.'){
                    building[ny][nx] = '*';
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
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        fire.clear();
        memset(visited, 0, sizeof(visited));
        cin >> w >> h;
        for(int height = 0; height < h; height++){
            cin >> building[height];
            for(int width = 0; width < w; width++){
                if(building[height][width] == '*'){
                    fire.push_back({width, height});
                }
                else if(building[height][width] == '@'){
                    start = {width, height};
                }
            }
        }
        int result = bfs(start);
        if(result < 0){
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << result << '\n';
        }
    }
    return 0;
}