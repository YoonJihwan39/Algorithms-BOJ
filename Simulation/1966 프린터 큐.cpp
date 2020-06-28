#include<iostream>
#include<queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int i = 0; i < N; i++){
            int priority;
            cin >> priority;
            q.push({i, priority});
            pq.push(priority);
        }
        int count = 0;
        while(!q.empty()){
            int current = q.front().first;
            int current_priority = q.front().second;
            q.pop();
            if(current_priority == pq.top()){
                pq.pop();
                count++;
                if(current == M){
                    break;
                }
            }
            else {
                q.push({current, current_priority});
            }
        }
        cout << count << '\n';
    }
    return 0;
}