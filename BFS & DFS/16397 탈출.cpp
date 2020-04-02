#include<iostream>
#include<queue>
using namespace std;

int N, T, G;
bool visited[100000];

struct Situation
{
    int num, cnt;
};


int bfs(){
    Situation start = {N, 0};
    queue<Situation> q;
    q.push(start);
    visited[N] = 1;
    while(!q.empty()){
        Situation current = q.front();
        q.pop();
        if(current.cnt > T) return -1;
        if(current.num == G) return current.cnt;
        //A버튼을 눌렀을 때
        if(current.num + 1 < 100000 && visited[current.num+1] == 0){
            q.push({current.num+1, current.cnt+1});
            visited[current.num+1] = 1;
        }
        int temp;
        //B버튼을 눌렀을 때
        if(current.num * 2 < 100000){
            //가장 큰 자리 수에서 1 빼기
            for(int i = 10000; i > 0; i /= 10){
                if(current.num * 2 / i != 0){
                    temp = current.num * 2 - i;
                    break;
                }
            }
            if(temp < 100000 && visited[temp] == 0){
                q.push({temp, current.cnt+1});
                visited[temp] = 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> T >> G;
    int result = bfs();
    if(result < 0) cout << "ANG";
    else cout << result;
    return 0;
}