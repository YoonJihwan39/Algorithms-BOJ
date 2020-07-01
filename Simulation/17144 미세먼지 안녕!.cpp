#include<iostream>
#include<vector>
using namespace std;

int R, C, T;
int A[50][50];
int device_x, device_y;
int upper_air_x, upper_air_y;
int lower_air_x, lower_air_y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct dust
{
    int x;
    int y;
    int amount;
};

vector<dust> v;

int Simulation(){
    int result = 0;
    //spread
    // 각 먼지에 대해 확산시킴
    for(int i = 0; i < v.size(); i++){
        int cx = v[i].x;
        int cy = v[i].y;
        int ca = v[i].amount;
        int numDir = 0;

        for(int j = 0; j < 4; j++){
            int nx = cx + dx[j];
            int ny = cy + dy[j];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C || A[nx][ny] == -1){
                continue;
            }

            A[nx][ny] += ca / 5;
            numDir++;
        }
        A[cx][cy] -= (ca / 5) * numDir;
    }

    //air cleaner
    //upper
    for(int i = upper_air_x-1; i > 0; i--){
        A[i][0] = A[i-1][0];
    }
    for(int i = 0; i < C-1; i++){
        A[0][i] = A[0][i+1];
    }
    for(int i = 0; i <= upper_air_x-1; i++){
        A[i][C-1] = A[i+1][C-1];
    }
    for(int i = C-1; i >= 2; i--){
        A[upper_air_x][i] = A[upper_air_x][i-1];
    }
    A[upper_air_x][1] = 0;
    //lower
    for(int i = lower_air_x+1; i < R-1; i++){
        A[i][0] = A[i+1][0];
    }
    for(int i = 0; i < C-1; i++){
        A[R-1][i] = A[R-1][i+1];
    }
    for(int i = R-1; i >= lower_air_x+1; i--){
        A[i][C-1] = A[i-1][C-1];
    }
    for(int i = C-1; i >= 2; i--){
        A[lower_air_x][i] = A[lower_air_x][i-1];
    }
    A[lower_air_x][1] = 0;

    //먼지를 다시 계산
    v.clear();
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(A[i][j] > 0){
                v.push_back({i, j, A[i][j]});
                result += A[i][j];
            }
        }
    }
    return result;

}

int main(){
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> A[i][j];
            if(A[i][j] == -1){
                device_x = i;
                device_y = j;
            }
            else if(A[i][j] > 0){
                v.push_back({i, j, A[i][j]});
            }
        }
    }
    upper_air_x = device_x-1;
    upper_air_y = device_y;
    lower_air_x = device_x;
    lower_air_y = device_y;
    int result;
    for(int i = 0; i < T; i++){
        result = Simulation();
    }
    cout << result;
    return 0;
}