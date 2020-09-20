#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, X;
vector<pair<int, int>> adj[1001];
bool visited[1001];
int time[1001];
int resultTime[1001];

int main(){
    cin >> N >> M >> X;
    int A, B, T;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> T;
        adj[A].push_back(make_pair(B, T));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for(int i = 1; i <= N; i++){
        fill(visited, visited+1001, 0);
        fill(time, time+1001, 987654321);

        PQ.push(make_pair(0, i));
        time[i] = 0;

        while(!PQ.empty()){
            int curr;
            do {
                curr = PQ.top().second;
                PQ.pop();
            }while(!PQ.empty() && visited[curr]);

            if(visited[curr]) break;

            visited[curr] = 1;
            for(auto &p: adj[curr]){
                int next = p.first, d= p.second;
                if(time[curr] + d < time[next]){
                    time[next] = time[curr] + d;
                    PQ.push(make_pair(time[next], next));
                }
            }
        }
        if(i == X){
            for(int j = 1; j <= N; j++){
                resultTime[j] += time[j];
            }
        }
        else{
            resultTime[i] += time[X];
        }
    }
    int result = 0;
    for(int i = 1; i <= N; i++){
        result = max(result, resultTime[i]);
    }
    cout << result;
    return 0;

}