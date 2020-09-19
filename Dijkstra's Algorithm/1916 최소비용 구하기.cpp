#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
vector<pair<int, int>> bus[1001];
bool visited[1001];
int fare[1001];

int main(){
    cin >> N >> M;
    int start, dest, fee;
    for(int i = 0; i < M; i++){
        cin >> start >> dest >> fee;
        bus[start].push_back(make_pair(dest, fee));
    }
    cin >> start >> dest;
    fill(fare, fare+1001, 987654321);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    fare[start] = 0;
    PQ.push(make_pair(0, start));

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
        for(auto &p: bus[curr]){
            int next = p.first, f = p.second;

            if(fare[curr] + f < fare[next]){
                fare[next] = fare[curr] + f;
                PQ.push(make_pair(fare[next], next));
            }
        }
    }
    cout << fare[dest];
    return 0;
}