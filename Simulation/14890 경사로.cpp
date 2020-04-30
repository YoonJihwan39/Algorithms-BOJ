#include<iostream>
#include<vector>
using namespace std;

int N, L;
int map[100][100];
int result = 0;

int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    // 가로 길 확인
    for(int row = 0; row < N; row++){
        bool fail = false;
        vector<int> v;
        int last_height = -1;
        for(int col = 0; col < N; col++){
            int current_height = map[row][col];
            // v가 비어있거나 마지막 것과 같은 높이면 push
            if(last_height == -1 || last_height == current_height) {
                v.push_back(current_height);
                last_height = current_height;
            }
            // 마지막 것보다 높이가 1 낮다면 발판을 둘 곳을 확보
            else if(last_height == current_height + 1){
                int current_L = 1;
                while(current_L < L){
                    // 도중에 높이가 다른 곳이 나오면 해당 경로는 실패
                    if(map[row][col+1] != current_height){
                        fail = true;
                        break;
                    }
                    else {
                        col++;
                        current_L++;
                    }
                }
                if(fail){
                    break;
                }
                else {
                    v.clear();
                    last_height--;
                }
            }
            // 마지막 것보다 높이가 1 높다면 발판을 둘 곳이 있는지 확인
            else if(last_height == current_height - 1){
                if(v.size() >= L){
                    v.clear();
                    v.push_back(current_height);
                    last_height++;
                }
                else {
                    fail = true;
                    break;
                }
            }
            // 위 경우가 아니라면 실패
            else {
                fail = true;
                break;
            }
        }
        if(!fail){
            result++;
        }
    }

    // 세로 길 확인
    for(int col = 0; col < N; col++){
        bool fail = false;
        vector<int> v;
        int last_height = -1;
        for(int row = 0; row < N; row++){
            int current_height = map[row][col];
            // v가 비어있거나 마지막 것과 같은 높이면 push
            if(last_height == -1 || last_height == current_height) {
                v.push_back(current_height);
                last_height = current_height;
            }
            // 마지막 것보다 높이가 1 낮다면 발판을 둘 곳을 확보
            else if(last_height == current_height + 1){
                int current_L = 1;
                while(current_L < L){
                    // 도중에 높이가 다른 곳이 나오면 해당 경로는 실패
                    if(map[row+1][col] != current_height){
                        fail = true;
                        break;
                    }
                    else {
                        row++;
                        current_L++;
                    }
                }
                if(fail){
                    break;
                }
                else {
                    v.clear();
                    last_height--;
                }
            }
            // 마지막 것보다 높이가 1 높다면 발판을 둘 곳이 있는지 확인
            else if(last_height == current_height - 1){
                if(v.size() >= L){
                    v.clear();
                    v.push_back(current_height);
                    last_height++;
                }
                else {
                    fail = true;
                    break;
                }
            }
            // 위 경우가 아니라면 실패
            else {
                fail = true;
                break;
            }
        }
        if(!fail){
            result++;
        }
    }
    cout << result;
    return 0;
}