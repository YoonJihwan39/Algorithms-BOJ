#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, from, to, m;
vector<int> v[101];
bool visited[101];

int bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(from, 0));
    visited[from] = 1;
    while(!q.empty()){
        pair<int, int>current = q.front();
        if(current.first == to){
            return current.second;
        }
        q.pop();
        for(int i = 0; i < v[current.first].size(); i++){
            if(visited[v[current.first][i]] == 0){
                q.push(make_pair(v[current.first][i], current.second+1));
                visited[v[current.first][i]] = 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;
    cin >> from >> to;
    cin >> m;
    int parent, child;
    for(int i = 0; i < m; i++){
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }
    cout << bfs();
    return 0;
}