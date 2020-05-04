#include<iostream>
#include<vector>
using namespace std;

int N;
bool map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

// 90도 회전은 각 점에서 마지막 점으로 향하는 벡터에서 x와 y를 바꾸고 y의 좌표를 바꾸는 것.
void draw_dragon_curve(int x, int y, int d, int g){
    map[y][x] = 1;
    vector<pair<int, int>> v;
    v.push_back(make_pair(x, y));
    for(int generation = 0; generation <= g; generation++){
        int last_point_x = v.back().first;
        int last_point_y = v.back().second;
        if(generation == 0){
            v.push_back(make_pair(x + dx[d], y + dy[d]));
            map[y + dy[d]][x + dx[d]] = 1;
        }
        else{
            // 각 점에 대해 90도 이동(뒤에서 부터)
            for(int i = v.size()-2; i >= 0; i--){
                int x_direction = last_point_x - v[i].first;
                int y_direction = last_point_y - v[i].second;
                int temp = x_direction;
                x_direction = y_direction;
                y_direction = temp * -1;
                v.push_back(make_pair(last_point_x + x_direction, last_point_y + y_direction));
                map[last_point_y + y_direction][last_point_x + x_direction] = 1;
            }
        }
    }
    return;
}


int main(){
    int result = 0;
    cin >> N;
    int x, y, d, g;
    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        draw_dragon_curve(x, y, d, g);
    }
    for(int i = 0; i <= 99; i++){
        for(int j = 0; j <= 99; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                result++;
            }
        }
    }
    cout << result;
    return 0;
}