// http://kks227.blog.me/220793134705 참고
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int N;
vector<int> adj[1000001], child[1000001];
bool visited[1000001];
int cache[1000001][2];

void dfs(int curr){
    visited[curr] = 1;
    for(auto &p: adj[curr]){
        if(visited[p] == false){
            child[curr].push_back(p);
            dfs(p);
        }
    }
    return;
}

int dp(int curr, int parent){
    if(cache[curr][parent] != -1){
        return cache[curr][parent];
    }

    
    int early = 1, late = (parent == 1) ? 0 : 987654321;
    for(auto &p: child[curr]){
        if(parent == 0){
            early += dp(p, 1);
        }
        else {
            early += dp(p, 1);
            late += dp(p, 0);
        }
    }
    int result = min(early, late);
    cache[curr][parent] = result;
    return result;
}

int main(){
    memset(cache, -1,  sizeof(cache));
    cin >> N;
    int u, v;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //root를 1로 설정하고 자식-부모 파악
    dfs(1);
    int result = min(dp(1, 0), dp(1, 1));
    cout << result;
    return 0;

}