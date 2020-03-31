#include<iostream>
#include<string>
#include<queue>
using namespace std;

string map[1000];
//맨 뒤가 1이면 아직 해머를 안 썼을 때, 0이면 쓴 후
bool visited[1000][1000][2];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//hammer가 1이면 아직 벽을 한번 부술 수 있음
struct Situation{
    int x, y, dist;
    bool hammer;
};

int bfs(){
    Situation start = {0, 0, 1, 1};
    visited[0][0][1] = 1;
    queue<Situation> q;
    q.push(start);
    
    while(!q.empty()){
        Situation current = q.front();
        q.pop();
        if(current.x == M-1 && current.y == N-1){
                return current.dist;
            }
        for(int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N){
                continue;
            }
            if(map[ny][nx] == '0' && visited[ny][nx][current.hammer] == 0){
                q.push({nx, ny, current.dist+1, current.hammer});
                visited[ny][nx][current.hammer] = 1;
            }
            //해머가 있을 경우 사용
            if(current.hammer == 1 && map[ny][nx] == '1' && visited[ny][nx][0] == 0){
                q.push({nx, ny, current.dist+1, 0});
                visited[ny][nx][0] = 1;
            }
        }
    }
    return -1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> map[i];
    }
    cout << bfs();
    return 0;
}  