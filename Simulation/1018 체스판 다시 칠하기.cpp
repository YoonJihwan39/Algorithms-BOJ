#include<iostream>
using namespace std;

int N, M;
string board[50];

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        cin >> board[i];
    }
    int result = 987654321;
    for(int start_x = 0; start_x <= N - 8; start_x++){
        for(int start_y = 0; start_y <= M - 8; start_y++){
            int cnt = 0;
            // 좌상단 색을 유지했을 때
            char start_color = board[start_x][start_y];
            for(int i = 0; i < 8; i++){
                int x = start_x + i;
                for(int j = 0; j < 8; j++){
                    int y = start_y + j;
                    // i + j 가 짝수면 시작점과 색이 같아야하고 홀수면 달라야함.
                    if((i + j) % 2 == 0 && board[x][y] != start_color){
                        cnt++;
                    }
                    if((i + j) % 2 == 1 && board[x][y] == start_color){
                        cnt++;
                    }
                }
            }
            result = min(cnt, result);
            cnt = 0;
            // 좌상단 색을 바꿨을 때
            if(start_color == 'W'){
                start_color = 'B';
            }
            else{
                start_color = 'W';
            }

            for(int i = 0; i < 8; i++){
                int x = start_x + i;
                for(int j = 0; j < 8; j++){
                    int y = start_y + j;
                    // i + j 가 짝수면 시작점과 색이 같아야하고 홀수면 달라야함.
                    if((i + j) % 2 == 0 && board[x][y] != start_color){
                        cnt++;
                    }
                    if((i + j) % 2 == 1 && board[x][y] == start_color){
                        cnt++;
                    }
                }
            }
            result = min(cnt, result);
        }
    }
    cout << result;
    return 0;
}