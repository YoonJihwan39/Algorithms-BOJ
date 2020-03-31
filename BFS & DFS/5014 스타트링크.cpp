#include<iostream>
#include<queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];

struct Situation
{
    int floor, time;
};


int bfs(){
    queue<Situation> q;
    q.push({S, 0});
    visited[S] = 1;
    Situation current;
    while(!q.empty()){
        current = q.front();
        if(current.floor == G){
            return current.time;
        }
        q.pop();
        int go_up = current.floor + U;
        int go_down = current.floor - D;

        if(go_up <= F && visited[go_up] == 0){
            q.push({go_up, current.time+1});
            visited[go_up] = 1;
        }
        if(go_down >= 1 && visited[go_down] == 0){
            q.push({go_down, current.time+1});
            visited[go_down] = 1;
        }
    }
    return -1;
}

int main(){
    cin >> F >> S >> G >> U >> D;
    bool visited[F];
    int result = bfs();
    if(result == -1){
        cout << "use the stairs";
    }
    else {
        cout << result;
    }
    return 0;
}