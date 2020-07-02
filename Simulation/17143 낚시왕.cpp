#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string.h>
using namespace std;

int R, C, M;
int map[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};



struct shark
{
    int r, c, s, d;
};

vector<int> alive;
vector<shark> all_sharks(10001);

int Simulation(){
    int result = 0;
    for(int fisher = 1; fisher <= C; fisher++){
        //같은 열에 가장 가까운 상어 잡음
        for(int i = 1; i <= R; i++){
            if(map[i][fisher] != 0){
                //alive에서 해당 상어 제거
                vector<int>::iterator iter;
                iter = find(alive.begin(), alive.end(), map[i][fisher]);
                alive.erase(iter);

                result += map[i][fisher];
                map[i][fisher] = 0;
                break;
            }
        }
        sort(alive.begin(), alive.end(), greater<int>());
        memset(map, 0, sizeof(map));
        //상어 이동(큰 상어부터)
        for(int i = 0; i < alive.size(); i++){
            int cz = alive[i];
            int cr = all_sharks[cz].r;
            int cc = all_sharks[cz].c;
            int cs = all_sharks[cz].s;
            int cd = all_sharks[cz].d;
            
            //속도만큼 이동
            for(int j = 0; j < cs; j++){
                int nr = cr + dx[cd];
                int nc = cc + dy[cd];

                //벽을 벗어난다면 방향을 반대로
                if(nr <= 0 || nc <= 0 || nr > R || nc > C){
                    if(cd == 0 || cd == 2){
                        cd++;
                    }
                    else{
                        cd--;
                    }
                    nr = cr + dx[cd];
                    nc = cc + dy[cd];
                }
                cr = nr;
                cc = nc;
            }

            //이동할 곳에 이미다른 상어가 있다면 큰 상어이므로 현재 상어는 죽음
            if(map[cr][cc] != 0){
                alive.erase(alive.begin()+i);
                i--;
            }
            else {
                map[cr][cc] = cz;
                // 바뀐 위치, 방향 저장
                all_sharks[cz].r = cr;
                all_sharks[cz].c = cc;
                all_sharks[cz].d = cd;
            }
        }
    }
    return result;
}

int main(){
    cin >> R >> C >> M;
    for(int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        map[r][c] = z;
        alive.push_back(z);
        all_sharks[z].r = r;
        all_sharks[z].c = c;
        all_sharks[z].s = ((d-1)/2 == 0) ? s % (2*(R-1)) : s % (2*(C-1));
        all_sharks[z].d = d-1;
    }
    cout << Simulation();
    return 0;
}