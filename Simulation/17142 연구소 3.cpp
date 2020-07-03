#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
//바이러스가 퍼진 곳은 3으로 표기
int map[50][50];
vector<pair<int, int>> all_virus;
int result = 987654321;
int empty_space = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Simulation(vector<int> active){
    int map_copy[50][50];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map_copy[i][j] = map[i][j];
        }
    }
    int empty_space_copy = empty_space;
    int time = 0;
    queue<pair<int, pair<int, int>>> q;
    //queue에 M개의 초기 활성화 바이러스 push
    for(int i = 0; i < active.size(); i++){
        q.push(make_pair(0, make_pair(all_virus[active[i]].first, all_virus[active[i]].second)));
        map_copy[all_virus[active[i]].first][all_virus[active[i]].second] = 3;
    }

    while(!q.empty() && empty_space_copy > 0){
        int ct = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            //map을 벗어나면 확산되지 않음
            if(nx < 0 || ny < 0 || nx >= N || ny >= N){
                continue;
            }
            //벽이 있거나 이미 바이러스가 있다면 확산되지 않음
            if(map_copy[nx][ny] == 1 || map_copy[nx][ny] == 3){
                continue;
            }
            
            
            if(map_copy[nx][ny] != 2){
                empty_space_copy--;
            }
            map_copy[nx][ny] = 3;
            time = max(time, ct+1);
            q.push(make_pair(ct+1, make_pair(nx, ny)));
        }
    }
    if(empty_space_copy == 0){
        
        result = min(result, time);
    }
    return;
}

void Combination(int n, vector<int> active){
    //active의 사이즈가 M이라면 시뮬레이션 시작
    if(active.size() == M){
        Simulation(active);
        return;
    }
    //n이 all virus를 넘어섰는데 M이 아니라면 그냥 종료
    else if(n == all_virus.size()){
        return;
    }
    //n번째 바이러스를 포함 안 시켰을 때
    Combination(n+1, active);

    ////n번째 바이러스를 포함 시켰을 때
    active.push_back(n);
    Combination(n+1, active);
    return;
}   

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                all_virus.push_back(make_pair(i, j));
            }
            else if(map[i][j] == 0){
                empty_space++;
            }
        }
    }
    vector<int> v;
    Combination(0, v);
    if(result == 987654321){
        result= -1;
    }
    cout << result;
    return 0;
}