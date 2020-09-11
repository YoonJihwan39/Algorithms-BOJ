#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct PIECE
{
    int x;
    int y;
    int dir;
};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int N, K;
int color[13][13];
stack<int> board[13][13];
vector<PIECE> piece;
bool finish = 0;

int main(){
    cin >> N >> K;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cin >> color[x][y];
        }
    }
    int inputX, inputY, inputDir;
    piece.push_back({0, 0, 0});
    for(int i = 1; i <= K; i++){
        cin >> inputX >> inputY >> inputDir;
        PIECE temp;
        temp.x = inputX;
        temp.y = inputY;
        temp.dir = inputDir;
        piece.push_back(temp);
        board[inputX][inputY].push(i);
    }

    int cnt = 1;
    while(cnt <= 1000){
        for(int i = 1; i < piece.size(); i++){
            bool move = 1;
            // 이동하려는 칸
            int cx = piece[i].x + dx[piece[i].dir];
            int cy = piece[i].y + dy[piece[i].dir];

            // 이동하려는 칸이 파란색이나 벗어나려는 경우
            if(cx <= 0 || cy <= 0 || cx > N || cy > N || color[cx][cy] == 2){
                //방향을 반대로 바꾸고 이동하려는 칸도 반대로 바꿈
                if(piece[i].dir == 1 || piece[i].dir == 3){
                    piece[i].dir++;
                }
                else {
                    piece[i].dir--;
                }
                cx = piece[i].x + dx[piece[i].dir];
                cy = piece[i].y + dy[piece[i].dir];
                //만약 이동하려는 칸이 또 파란색이면 움직이지 않음
                if(cx <= 0 || cy <= 0 || cx > N || cy > N || color[cx][cy] == 2){
                    move = 0;
                }
            }
            // 이동하려는 칸이 흰색인 경우
            if(move == 1 && color[cx][cy] == 0){
                stack<int> temp;
                // 현재 말이 나올 때까지 위에 있는 말을 temp로 옮김
                while(board[piece[i].x][piece[i].y].top() != i){
                    temp.push(board[piece[i].x][piece[i].y].top());
                    board[piece[i].x][piece[i].y].pop();
                }
                temp.push(i);
                board[piece[i].x][piece[i].y].pop();

                // 이동시키려는 칸으로 옮김+말의 위치도 수정
                while(!temp.empty()){
                    board[cx][cy].push(temp.top());
                    piece[temp.top()].x = cx;
                    piece[temp.top()].y = cy;
                    temp.pop();
                }
                //이후 4개 이상이면 종료
                if(board[cx][cy].size() >= 4){
                    finish = 1;
                    break;
                }
            }
            // 이동하려는 칸이 빨간색인 경우
            if(move == 1 && color[cx][cy] == 1){
                stack<int> temp;
                // 현재 말이 나올 때까지 위에 있는 말을 temp로 옮김
                while(board[piece[i].x][piece[i].y].top() != i){
                    temp.push(board[piece[i].x][piece[i].y].top());
                    board[piece[i].x][piece[i].y].pop();
                }
                temp.push(i);
                board[piece[i].x][piece[i].y].pop();

                // 이동시키려는 칸으로 옮김+말의 위치도 수정
                while(!temp.empty()){
                    board[cx][cy].push(temp.top());
                    piece[temp.top()].x = cx;
                    piece[temp.top()].y = cy;
                    temp.pop();
                }
                //이후 4개 이상이면 종료
                if(board[cx][cy].size() >= 4){
                    finish = 1;
                    break;
                }
                //순서 뒤집기
                queue<int> reverse;
                while(board[cx][cy].top() != i){
                    reverse.push(board[cx][cy].top());
                    board[cx][cy].pop();
                }
                reverse.push(board[cx][cy].top());
                board[cx][cy].pop();
                while(!reverse.empty()){
                    board[cx][cy].push(reverse.front());
                    reverse.pop();
                }
            }
        }
        if(finish){
            break;
        }
        cnt++;
    }
    if(finish){
        cout << cnt;
    }
    else {
        cout << -1;
    }
    return 0;

}