#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N;
vector<int> path[100];
bool visited[100];
bool result[100][100];

void dfs(int from, int now){
    for(int i = 0; i < path[now].size(); i++){
        int next_point = path[now][i];
        if(visited[next_point] == 0){
            visited[next_point] = 1;
            result[from][next_point] = 1;
            dfs(from, next_point);
        }
    }
    return;
}

int main(){
    cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            //입력이 1이면 path[i]에 j를 추가함.
            if(input == 1){
                path[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < N; i++){
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << result[i][j];
            if(j != N-1){
                cout << ' ';
            }
        }
        if(i != N-1){
            cout << '\n';
        }
    }
    return 0;

}