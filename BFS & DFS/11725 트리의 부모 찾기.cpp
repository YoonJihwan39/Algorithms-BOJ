#include<iostream>
#include<vector>
using namespace std;

int N;
int parent[100001];
vector<vector<int>> v(100001);
bool visited[100001];

void dfs(int n){
    visited[1] = 1;
    for(int i = 0; i < v[n].size(); i++){
        if(visited[v[n][i]] == 0){
            visited[v[n][i]] = 1;
            parent[v[n][i]] = n;
            dfs(v[n][i]);
        }
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int input1, input2;
    for(int i = 0; i < N-1; i++){
        cin >> input1 >> input2;
        v[input1].push_back(input2);
        v[input2].push_back(input1);
    }

    dfs(1);

    for(int i = 2; i <= N; i++){
        cout << parent[i] << '\n';
    }
    return 0;
}