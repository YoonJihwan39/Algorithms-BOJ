#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, L, R;
int A[50][50];
int cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs(){
    bool changed = 0;
    bool visited[50][50] = {0, };
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 1){
                continue;
            }
            int numUnion = 0;
            int sumUnion = 0;
            queue<pair<int, int>> q;
            vector<pair<int, int>> v;
            q.push(make_pair(i, j));
            v.push_back(make_pair(i, j));
            visited[i][j] = 1;
            while(!q.empty()){
                int current_y = q.front().first;
                int current_x = q.front().second;
                q.pop();
                numUnion++;
                sumUnion += A[current_y][current_x];

                for(int i = 0; i < 4; i++){
                    int ny = current_y + dy[i];
                    int nx = current_x + dx[i];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= N){
                        continue;
                    }
                    if(visited[ny][nx] == 1){
                        continue;
                    }
                    //인구 수 차이가 L와 R 사이라면 queue와 vector에 push
                    int gap = (A[current_y][current_x] - A[ny][nx] >= 0) ? A[current_y][current_x] - A[ny][nx] : A[ny][nx] - A[current_y][current_x];
                    if(gap >= L && gap <= R){
                        q.push(make_pair(ny, nx));
                        v.push_back(make_pair(ny, nx));
                        visited[ny][nx] = 1;
                    } 
                }
            }
            //연합이 생겼다면 평균을 구하고 각 국가의 인구를 맞춤
            if(numUnion > 1){
                changed = 1;
                int avgUnion = sumUnion / numUnion;
                for(int k = 0; k < v.size(); k++){
                    A[v[k].first][v[k].second] = avgUnion;
                }
            }
        }
    }
    return changed;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    //변화가 없을 때까지 bfs 반복
    while(1){
        bool changed = bfs();
        cnt++;
        if(changed == 0){
            cnt--;
            break;
        }
    }
    cout << cnt;
    return 0;
}