#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int R, C;
int r, c, k;
vector<vector<int>> board (4, vector<int> (4, 0)); 

void Simulation(){
    // R연산
    if(R >= C){
        for(int i = 1; i <= R; i++){
            vector<pair<int, int>> v;
            for(int j = 1; j <= C; j++){
                int current = board[i][j];
                if(current == 0){
                    continue;
                }
                if(v.empty()){
                    v.push_back(make_pair(1, current));
                }
                else{
                    for(int k = 0; k < v.size(); k++){
                        if(v[k].second == current){
                            v[k].first++;
                            break;
                        }
                        //마지막까지 current가 없다면 push
                        else if(k == v.size()-1){
                            v.push_back(make_pair(1, current));
                            break;
                        }
                    }
                }
            }
            sort(v.begin(), v.end());
            // 열 크기 조정
            if(2 * v.size() > C){
                int gap = 2 * v.size() - C;
                for(int j = 1; j <= R; j++){
                    for(int k = 0; k < gap; k++){
                        board[j].push_back(0);
                    }
                }
                C += gap;
            }
            // 수 입력
            for(int j = 0; j < v.size(); j++){
                board[i][2*j+1] = v[j].second;
                board[i][2*j+2] = v[j].first;
            }
            // padding
            for(int j = 2 * v.size() + 1; j <= C; j++){
                board[i][j] = 0;
            }
        }
    }
    //C연산
    else{
        for(int i = 1; i <= C; i++){
            vector<pair<int, int>> v;
            for(int j = 1; j <= R; j++){
                int current = board[j][i];
                if(current == 0){
                    continue;
                }
                if(v.empty()){
                    v.push_back(make_pair(1, current));
                }
                else{
                    for(int k = 0; k < v.size(); k++){
                        if(v[k].second == current){
                            v[k].first++;
                            break;
                        }
                        //마지막까지 current가 없다면 push
                        else if(k == v.size()-1){
                            v.push_back(make_pair(1, current));
                            break;
                        }
                    }
                }
            }
            sort(v.begin(), v.end());
            // 행 크기 조정
            if(2 * v.size() > R){
                int gap = 2 * v.size() - R;
                for(int j = 0; j < gap; j++){
                    board.push_back(vector<int> (C+1, 0));
                }
                R += gap;
            }
            // 수+등장횟수 입력
            for(int j = 0; j < v.size(); j++){
                board[2*j+1][i] = v[j].second;
                board[2*j+2][i] = v[j].first;
            }
            // padding
            for(int j = 2 * v.size() + 1; j <= R; j++){
                board[j][i] = 0;
            }
        }
    }
    return;
}

int main(){
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> board[i][j];
        }
    }
    R = 3;
    C = 3;
    int result = 0;
    while(R < r || C < c || board[r][c] != k){
        if(result >= 100){
            result = -1;
            break;
        }
        Simulation();
        result++;
        /*
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
        */
        //cout << "==================================\n";
    }
    cout << result;
    return 0;
}