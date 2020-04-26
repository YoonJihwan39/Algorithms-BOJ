#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[8][8];
int size_of_vacant;
vector<pair<int, int>> virus;
vector<pair<int, int>> vacant;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(){
    int result = size_of_vacant;
    int map_copy[8][8];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map_copy[i][j] = map[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < virus.size(); i++){
        q.push(make_pair(virus[i].first, virus[i].second));
    }
    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = current_y + dy[i];
            int nx = current_x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M){
                continue;
            }
            if(map_copy[ny][nx] == 0){
                q.push(make_pair(ny, nx));
                map_copy[ny][nx] = 2;
                result--;
            }
        }
    }
    return result;
}

int main(){
    int result = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }
            else if(map[i][j] == 0){
                vacant.push_back(make_pair(i, j));
            }
        }
    }
    size_of_vacant = vacant.size()-3;

    for(int first_wall = 0; first_wall < vacant.size()-2; first_wall++){
        map[vacant[first_wall].first][vacant[first_wall].second] = 1;
        for(int second_wall = first_wall+1; second_wall < vacant.size()-1; second_wall++){
            map[vacant[second_wall].first][vacant[second_wall].second] = 1;
            for(int third_wall = second_wall+1; third_wall < vacant.size(); third_wall++){
                map[vacant[third_wall].first][vacant[third_wall].second] = 1;

                result = max(result, bfs());

                map[vacant[third_wall].first][vacant[third_wall].second] = 0;

            }
            map[vacant[second_wall].first][vacant[second_wall].second] = 0;
        }
        map[vacant[first_wall].first][vacant[first_wall].second] = 0;
    }
    cout << result;
    return 0;
}