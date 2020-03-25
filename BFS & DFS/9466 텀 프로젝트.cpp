#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int T, n;
int student[100001];
bool visited[100001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> student[i];
        }

        for(int i = 1; i <= n; i++){
            queue<int> q;
            int current = i;
            if(visited[current] == 1){
                continue;
            }
            q.push(current);
            visited[i] = 1;
            while(1){
                //다음 학생이 방문되지 않았으면 다음 학생으로 이동
                if(visited[student[current]] == 0){
                    current = student[current];
                    visited[current] = 1;
                    q.push(current);
                }
                //방문된 적이 있다면 큐에 해당 학생이 나올 때까지 pop하면서 cnt증가
                else {
                    while(!q.empty() && q.front() != student[current]){
                        q.pop();
                        cnt++;
                    }
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}