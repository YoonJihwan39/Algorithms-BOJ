#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct NODE{
    int next;
    int cycle = 0;
    int cycleCnt = 0;
    int varCnt = 0;
};

int n, k, list_size;
int dp[1001][1001];
bool visited[1001];
bool checked[1001];
NODE node[1001];
queue<int> q;
vector<pair<int, int>> list;

int dfs(int x){
    visited[x] = 1;
    int next = node[x].next;
    int cycle = 0;
    //다음 노드가 확인이 안되어 있다면 
    if(checked[next] == false){
        //방문한 적이 있다면(cycle)
        if(visited[next]){
            int cnt = 1;
            node[x].cycle = x;
            while(next != x){
                cnt++;
                node[next].cycle = x;
                next = node[next].next;
            }
            //cycle에 있는 node의 크기
            node[x].cycleCnt = cnt;
            //cycle에서 가변 node의 수
            node[x].varCnt = -cnt;
            q.push(x);
            cycle = x;
        }
        else{
            cycle = dfs(next);
        }
    }
    else {
        cycle = node[next].cycle;
    }

    checked[x] = 1;
    node[x].cycle = cycle;
    node[cycle].varCnt++;
    return cycle;
}

int main(){
    cin >> n >> k;
    //i번째 노드의 다음 node를 저장
    for(int i = 1; i <= n; i++){
        cin >> node[i].next;
    }
    // 각 node를 dfs로 탐색
    for(int i = 1; i <= n; i++){
        if(checked[i] == false){
            dfs(i);
        }
    }

    int c = 0;
    while(!q.empty()){
        c = q.front();
        q.pop();
        if(node[c].cycleCnt > k){
            continue;
        }
        //list에 각 cycle의 노드 수와 가변 노드 수를 저장
        list.push_back(make_pair(node[c].cycleCnt, node[c].varCnt));
    }

    list.push_back(make_pair(0, 0));
    sort(list.begin(), list.end());
    list_size = list.size();

    memset(dp, -1, sizeof(dp));

    int w, v;
    for(int i = 1; i < list_size; i++){
        w = list[i].first;
        v = list[i].second;
        dp[i][w] = v;
        for(int j = 1; j <= k; j++){
            //i번째 cycle에서 j명까지 허용되었을 때의 최대 가치
            if(j > w){
                if(dp[i-1][j-w] >= 0){
                    dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j]);
                }
                else{
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
            }
            else{
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= k; i++){
        if(dp[list_size-1][i] >= 0){
            ans = max(ans, i + dp[list_size-1][i]);
        }
    }
    if(ans > k){
        cout << k;
    }
    else {
        cout << ans;
    }
    return 0;
}
