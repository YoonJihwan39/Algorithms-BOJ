// http://kks227.blog.me/220796029558 참고
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int V, E, K;
    vector<pair<int, int>> adj[20000];
    cin >> V >> E >> K;
    K--;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back(make_pair(v-1, w));
    }

    int dist[20000];
    fill(dist, dist+20000, 987654321);
    bool visited[20000] = {0, };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    dist[K] = 0;
    PQ.push(make_pair(0, K));
    while(!PQ.empty()){
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]);

        if(visited[curr]) {
            break;
        }

        visited[curr] = true;
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;

            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                PQ.push(make_pair(dist[next], next));
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dist[i] == 987654321){
            cout << "INF\n";
        }
        else {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}