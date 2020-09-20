#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int M, N;
int map[100][100];
int dist[100][100];
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(){
    cin >> M >> N;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            map[i][j] = input[j] - '0';
            dist[i][j] = 987654321;
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;
    dist[0][0] = 0;
    PQ.push(make_pair(0, make_pair(0, 0)));

    while(!PQ.empty()){
        int cx, cy;
        do{
            cx = PQ.top().second.first;
            cy = PQ.top().second.second;
            PQ.pop();
        }while(!PQ.empty() && visited[cx][cy]);

        if(visited[cx][cy]) break;

        visited[cx][cy] = 1;

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            int nDist = dist[cx][cy] + map[nx][ny];

            if(dist[nx][ny] > nDist){
                dist[nx][ny] = nDist;
                PQ.push(make_pair(nDist, make_pair(nx, ny)));
            }
        }
    }
    cout << dist[N-1][M-1];
    return 0;
    
}