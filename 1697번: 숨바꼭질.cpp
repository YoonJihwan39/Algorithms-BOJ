#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 100001
int N, K;
bool visit[MAX_SIZE];

int bfs() {
    int day = 0;
    queue<pair<int, int>> q;
    visit[N] = 1;
    q.push(make_pair(N, 0));
    
    while(!q.empty()){
        int pos = q.front().first;
        int time = q.front().second;
        visit[pos] = 1;
        if(pos == K){
            return time;
        }

        q.pop();

        if(2 * pos <= 100000 && !visit[2*pos]){
            q.push(make_pair(2*pos, time+1));
        }
        if(pos - 1 >= 0 && !visit[pos-1]){
            q.push(make_pair(pos-1, time+1));
        }
        if(pos + 1 <= 100000 && !visit[pos+1]){
            q.push(make_pair(pos+1, time+1));
        }
    }
}

int main(){
    cin >> N >> K;
    cout << bfs();
    return 0;
}
