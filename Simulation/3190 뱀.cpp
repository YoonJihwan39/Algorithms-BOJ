#include<iostream>
#include<queue>
using namespace std;

int N, K, L;
int map[101][101]; // 1이면 사과 -1이면 뱀
int direction[10001]; // -1이면 왼쪽으로 1이면 오른쪽으로
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q; // 뱀의 몸의 위치

int main(){
    cin >> N >>K;
    for(int i = 0; i < K; i++){
        int y, x;
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int input_time;
        char input_dir;
        cin >> input_time >> input_dir;
        if(input_dir == 'L'){
            direction[input_time] = -1;
        }
        else {
            direction[input_time] = 1;
        }
    }
    int current_y = 1, current_x = 1;
    map[1][1] = -1;
    q.push(make_pair(1, 1));
    int current_dir = 0;
    int time = 0;
    while(1){
        time++;
        current_y += dy[current_dir];
        current_x += dx[current_dir];
        //다음 이동할 곳이 벽이라면 끝냄
        if(current_y < 1 || current_x < 1 || current_y > N || current_x > N){
            break;
        }
        //다음 이동할 곳이 몸과 부딫히면 끝냄
        if(map[current_y][current_x] == -1){
            break;
        }
        //다음 이동할 곳이 사과라면 사과를 먹고 몸이 길어짐
        if(map[current_y][current_x] == 1){
            map[current_y][current_x] = -1;
            q.push(make_pair(current_y, current_x));
        }
        //다음 이동할 곳이 비어있다면 꼬리를 pop하고 머리를 push
        else {
            map[current_y][current_x] = -1;
            q.push(make_pair(current_y, current_x));
            int tail_y = q.front().first;
            int tail_x = q.front().second;
            q.pop();
            map[tail_y][tail_x] = 0;
        }
        // 방향을 바꿀 시간이면 바꿈
        if(direction[time] != 0){
            current_dir = (current_dir + direction[time]) % 4;
            current_dir = (current_dir < 0) ? current_dir + 4 : current_dir;
        }
    }
    cout << time;
    return 0;
}