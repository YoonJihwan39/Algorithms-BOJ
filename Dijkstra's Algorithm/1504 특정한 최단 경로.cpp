#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, E;
int a, b, c;
vector<pair<int, int>> adj[801];
bool visited[801];
int dist[801];

int main(){
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    cin >> a >> b;

    //1에서 a와 b까지의 최소 거리
    fill(dist, dist+801, 987654321);
    fill(visited, visited+801, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    dist[1] = 0;
    PQ.push(make_pair(0, 1));
    while(!PQ.empty()){
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]);

        if(visited[curr]){
            break;
        }

        visited[curr] = 1;
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;
            if(dist[curr] + d < dist[next]){
                dist[next] = dist[curr] + d;
                PQ.push(make_pair(dist[next], next));
            }
        }
    }
    int oneToA = dist[a];
    int oneToB = dist[b];

    //a에서 b와 N까지의 최소 거리
    fill(dist, dist+801, 987654321);
    fill(visited, visited+801, 0);

    dist[a] = 0;
    PQ.push(make_pair(0, a));
    while(!PQ.empty()){
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]);

        if(visited[curr]){
            break;
        }

        visited[curr] = 1;
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;
            if(dist[curr] + d < dist[next]){
                dist[next] = dist[curr] + d;
                PQ.push(make_pair(dist[next], next));
            }
        }
    }
    int aToB = dist[b];
    int aToN = dist[N];
    
    //b에서 a와 N까지의 최소 거리
    fill(dist, dist+801, 987654321);
    fill(visited, visited+801, 0);

    dist[b] = 0;
    PQ.push(make_pair(0, b));
    while(!PQ.empty()){
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]);

        if(visited[curr]){
            break;
        }

        visited[curr] = 1;
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;
            if(dist[curr] + d < dist[next]){
                dist[next] = dist[curr] + d;
                PQ.push(make_pair(dist[next], next));
            }
        }
    }
    int bToA = dist[a];
    int bToN = dist[N];

    int oneToAToBtoN;
    int oneToBToAtoN;

    if(oneToA != 987654321 && aToB != 987654321 && bToN != 987654321){
        oneToAToBtoN = oneToA + aToB + bToN;
    }
    else {
        oneToAToBtoN = 987654321;
    }

    if(oneToB != 987654321 && bToA != 987654321 && aToN != 987654321){
        oneToBToAtoN = oneToB + bToA + aToN;
    }
    else {
        oneToBToAtoN = 987654321;
    }

    int result = min(oneToAToBtoN, oneToBToAtoN);

    if(result == 987654321){
        cout << -1;
    }
    else {
        cout << result;
    }

    return 0;

}