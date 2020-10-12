#include<iostream>
#include<vector>
#include<list>
#include<string.h>
#include<queue>
using namespace std;

int N, M, T;
vector<vector<int>> circle(1, vector<int>(1, 0));
bool visited[51][51];
bool deleted[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    cin >> N >> M >> T;
    int input;
    for(int i = 1; i <= N; i++){
        vector<int> temp;
        for(int j = 0; j < M; j++){
            cin >> input;
            temp.push_back(input);
        }
        circle.push_back(temp);
    }
    int x, d, k;
    for(int i = 0; i < T; i++){
        cin >> x >> d >> k;
        for(int j = 1; j <= N; j++){
            if(j % x != 0){
                continue;
            }
            list<int> l;
            for(int a = 0; a < M; a++){
                l.push_back(circle[j][a]);
            }
            if(d == 0){
                for(int a = 0; a < k; a++){
                    int temp = l.back();
                    l.pop_back();
                    l.push_front(temp);
                }
            }
            else {
                for(int a = 0; a < k; a++){
                    int temp = l.front();
                    l.pop_front();
                    l.push_back(temp);
                }
            }
            for(int a = 0; a < M; a++){
                circle[j][a] = l.front();
                l.pop_front();
            }
        }

        memset(visited, 0, sizeof(visited));
        memset(deleted, 0, sizeof(deleted));
        bool totalfound = 0;
        int sum = 0;
        int cnt = 0;
        for(int a = 1; a <= N; a++){
            for(int b = 0; b < M; b++){
                if(visited[a][b] == 1 || circle[a][b] == -1){
                    continue;
                }
                visited[a][b] = 1;
                sum += circle[a][b];
                cnt++;
                for(int c = 0; c < 4; c++){
                    int ni = a + dx[c];
                    int nj = b + dy[c];

                    if(ni <= 0 || ni > N){
                        continue;
                    }
                    if(nj == -1){
                        nj = M-1;
                    }
                    else if(nj == M){
                        nj = 0;
                    }
                    if(visited[ni][nj] != 1 && circle[a][b] == circle[ni][nj]){
                        totalfound = 1;
                        deleted[a][b] = 1;
                        deleted[ni][nj] = 1;
                    }
                }
            }
        }
        for(int a = 1; a <= N; a++){
            for(int b = 0; b < M; b++){
                if(deleted[a][b]) circle[a][b] = -1;
            }
        }
        double avg = sum / (double)cnt;
        if(totalfound == 0){
            for(int a = 1; a <= N; a++){
                for(int b = 0; b < M; b++){
                    if(circle[a][b] == -1) continue;
                    if(circle[a][b] > avg){
                        circle[a][b]--;
                    }
                    else if(circle[a][b] < avg){
                        circle[a][b]++;
                    }
                }
            }
        }
    }
    int result = 0;
    for(int a = 1; a <= N; a++){
        for(int b = 0; b < M; b++){
            if(circle[a][b] == -1) continue;
            result += circle[a][b];
        }
    }
    cout << result;
    return 0;
}