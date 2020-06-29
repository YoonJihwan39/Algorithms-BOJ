#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int N, M, K;
int A[11][11];
int land[11][11];
deque<int> dq[11][11];
int total_tree = 0;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void one_year(){
    //spring&summer
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int added_nutrient = 0;
            for(int k = 0; k < dq[i][j].size(); k++){
                //영양분이 충분히 있다면 섭취하고 나이증가
                if(land[i][j] >= dq[i][j][k]){
                    land[i][j] -= dq[i][j][k];
                    dq[i][j][k]++;
                }
                //충분하지 않다면 이 나무 포함 뒤에 나무 모두 죽음
                else{
                    for(int l = dq[i][j].size()-1; l >= k; l--){
                        added_nutrient += (dq[i][j][l] / 2);
                        dq[i][j].pop_back();
                        total_tree--;
                    }
                    break;
                }
            }
            //여름에 영양분 증가
            land[i][j] += added_nutrient;
        }
    }

    //autumn
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 0; k < dq[i][j].size(); k++){
                // 나이가 5의 배수가 아니라면 continue
                if(dq[i][j][k] % 5){
                    continue;
                }
                for(int l = 0; l < 8; l++){
                    int nx = i + dx[l];
                    int ny = j + dy[l];

                    if(nx <= 0 || ny <= 0 || nx > N || ny > N){
                        continue;
                    }
                    dq[nx][ny].push_front(1);
                    total_tree++;
                }
            }
        }
    }

    //winter
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            land[i][j] += A[i][j];
        }
    }
    return;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    total_tree = M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
            land[i][j] = 5;
        }
    }
    for(int i = 0; i < M; i++){
        int x, y, age;
        cin >> x >> y >> age;
        dq[x][y].push_back(age);
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            sort(dq[i][j].begin(), dq[i][j].end());
        }
    }
    /*
    for(int i = 0; i < M; i++){
        cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << "\n";
    }
    return 0;
    */
    
    for(int i = 0; i < K; i++){
        one_year();
    }
    cout << total_tree;
    return 0;
}