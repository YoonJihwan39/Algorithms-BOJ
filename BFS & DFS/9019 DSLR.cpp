#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int T, A, B;
bool visited[10000];

struct Situation
{
    int value;
    string command;
};


string bfs(){
    queue<Situation> q;
    Situation start = {A, ""};
    q.push(start);
    visited[A] = 1;
    while(!q.empty()){
        Situation current = q.front();
        q.pop();
        if(current.value == B) return current.command;
        // D를 눌렀을 때
        int after_D = (current.value * 2) % 10000;
        if(visited[after_D] == 0){
            q.push({after_D, current.command+"D"});
            visited[after_D] = 1;
        }
        // S를 눌렀을 때
        int after_S = (current.value == 0) ? 9999 : current.value-1;
        if(visited[after_S] == 0){
            q.push({after_S, current.command+"S"});
            visited[after_S] = 1;
        }
        // L을 눌렀을 때
        int after_L = (current.value * 10) % 10000 + (current.value / 1000);
        if(visited[after_L] == 0){
            q.push({after_L, current.command+"L"});
            visited[after_L] = 1;
        }
        // R을 눌렀을 때
        int after_R = (current.value % 10) * 1000 + (current.value / 10);
        if(visited[after_R] == 0){
            q.push({after_R, current.command+"R"});
            visited[after_R] = 1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        memset(visited, 0, sizeof(visited));
        cin >> A >> B;
        cout << bfs() << '\n';
    }
    return 0;
}