#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int N, M;
string map[50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[64][50][50];

struct STATUS
{
    int x;
    int y;
    int dist;
    int keys;
};


int main(){
    cin >> N >> M;
    int startX, startY;
    for(int i = 0; i < N; i++){
        cin >> map[i];
        for(int j = 0; j < M; j++){
            if(map[i][j] == '0'){
                startX = i;
                startY = j;
                map[i][j] = '.';
            }
        }
    }
    vector<char> temp;
    queue<STATUS> q;
    STATUS start = {startX, startY, 0, 0};
    visited[0][startX][startY] = 1; 
    q.push(start);

    int result = -1;

    while(!q.empty()){
        STATUS curr = q.front();
        q.pop();
        if(map[curr.x][curr.y] == '1'){
            result = curr.dist;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[curr.keys][nx][ny]) continue;

            if(map[nx][ny] == '.' || map[nx][ny] == '1'){
                visited[curr.keys][nx][ny] = 1;
                q.push({nx, ny, curr.dist+1, curr.keys});
            }
            else if(map[nx][ny] >= 'a' && map[nx][ny] <= 'f'){
                int newkeys = curr.keys | (1 << (map[nx][ny] - 97));
                visited[newkeys][nx][ny] = 1;
                q.push({nx, ny, curr.dist+1, newkeys});
            }
            else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'F'){
                if(curr.keys & (1 << (map[nx][ny] - 65))){
                    visited[curr.keys][nx][ny] = 1;
                    q.push({nx, ny, curr.dist+1, curr.keys});
                }
            }
        }
    }
    cout << result;
    return 0;


}