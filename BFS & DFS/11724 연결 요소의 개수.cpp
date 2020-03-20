#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> connected[1001];
int visited[1001];

void dfs(int start){
    visited[start] = 1;
    for(int i = 0; i < connected[start].size(); i++){
        if(visited[connected[start][i]] == 0){
            dfs(connected[start][i]);
        }
    }
    return;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        connected[x].push_back(y);
        connected[y].push_back(x);
    }
    int cnt = 0;
    //방문하지 않은 점이 있을 경우 cnt증가, 그리고 dfs로 탐색하여 연결된 점을 방문
    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}