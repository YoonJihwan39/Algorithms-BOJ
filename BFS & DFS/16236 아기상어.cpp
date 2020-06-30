#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int map[20][20];
int N;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct shark
{
    int x;
    int y;
    int time;
};
shark start;
int shark_size = 2;
int shark_cnt = 0;

int bfs(){
    bool visited[20][20];
    bool target_on = 0;
    int target_time;
    vector<pair<int, int>> targetPos;
    memset(visited, 0, sizeof(visited));
    int count = 0;
    queue<shark> q;
    visited[start.x][start.y] = 1;
    q.push(start);

    while(!q.empty()){
        shark current = q.front();
        q.pop();
        //현재 공간에 물고기가 있고 자기보다 작다면 목표로 지정
        if(target_on == 0 && map[current.x][current.y] != 0 && map[current.x][current.y] < shark_size){
            target_on = 1;
            target_time = current.time;
            targetPos.push_back(make_pair(current.x, current.y));
        }
        if(target_on == 1 && map[current.x][current.y] != 0 && map[current.x][current.y] < shark_size){
            if(target_time == current.time){
                targetPos.push_back(make_pair(current.x, current.y));
            }
        }
        // 목표가 정해지면 더 이상 나아가는 것은 안됨.
        if(target_on == 0 || current.time < target_time){
            for(int i = 0; i < 4; i++){
                shark next = {current.x + dx[i], current.y + dy[i], current.time+1};

                if(next.x < 0 || next.y < 0 || next.x >= N || next.y >= N){
                    continue;
                }
                if(map[next.x][next.y] > shark_size){
                    continue;
                }
                if(visited[next.x][next.y] == 0){
                    visited[next.x][next.y] = 1;
                    q.push(next);
                }
            }
        }

        // 목표가 있고 큐가 비었다면 목표물 중 가장 위, 왼쪽에 있는 물고기를 먹음.
        if(target_on == 1 && q.empty()){
            sort(targetPos.begin(), targetPos.end());
            map[targetPos[0].first][targetPos[0].second] = 0;

            shark another_start = {targetPos[0].first, targetPos[0].second, 0};
            count += target_time;
            shark_cnt++;
            // 상어가 잡은 물고기와 크기가 같다면 성장
            if(shark_size == shark_cnt){
                shark_size++;
                shark_cnt = 0;
            }
            //queue와 visited를 초기화하고 다시 시작
            memset(visited, 0, sizeof(visited));
            while(!q.empty()) q.pop();

            visited[targetPos[0].first][targetPos[0].second] = 1;
            targetPos.clear();
            q.push(another_start);
            target_on = 0;
        }
    }
    return count;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                start.x = i;
                start.y = j;
                start.time = 0;
                map[i][j] = 0;
            }
        }
    }
    cout << bfs();
    return 0;
}