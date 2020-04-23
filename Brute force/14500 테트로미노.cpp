#include<iostream>
#include<vector>
using namespace std;

int N, M;
int map[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int y, int x, vector<pair<int, int>> v){
    int result = 0;
    //블록의 개수가 4면 현재 값 반환
    if(v.size() == 4){
        return map[y][x];
    }
    
    int max1 = 0, max2 = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= N || nx >= M){
            continue;
        }
        bool overlap = 0;
        for(int j = 0; j < v.size(); j++){
            if(v[j].first == ny && v[j].second == nx){
                overlap = 1;
                break;
            }
        }
        if(!overlap){
            v.push_back(make_pair(ny, nx));
            result = max(result, dfs(ny, nx, v));
            v.pop_back();
            // ㅜ 모양도 만들기 위해 현재 크기가 2라면 해당 점에서 인접한 가장 큰 2점을 알아냄
            if(v.size() == 2){
                if(map[ny][nx] > max2){
                    if(map[ny][nx] > max1){
                        max2 = max1;
                        max1 = map[ny][nx];
                    }
                    else {
                        max2 = map[ny][nx];
                    }
                }
            }
        }
    }
    if(v.size() == 2 && max1*max2 != 0){
        result = max(result, max1+max2);
    }
    return result + map[y][x];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            vector<pair<int, int>> v;
            v.push_back(make_pair(i, j));
            result = max(result, dfs(i, j, v));
        }
    }
    cout << result;
    return 0;
}