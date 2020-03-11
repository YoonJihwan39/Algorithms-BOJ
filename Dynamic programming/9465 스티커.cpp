//참고: http://kks227.blog.me/220777103650 
#include<iostream>
#include<cstring>
using namespace std;

int n;
int sticker[100001][2];
int cache[100001][3];

//status가 0이면 해당 열에서는 떼지않음, 1과 2면 해당 줄을 뗌.
int get_max_score(int col, int status){
    int result = 0;
    if(status != 0){
        result = sticker[col][status-1];
    }
    if(col == n){
        return result;
    }
    if(cache[col][status] != -1){
        return cache[col][status];
    }
    
    int maximum = 0;
    if(status == 0){
        maximum = max(get_max_score(col+1, 0), get_max_score(col+1, 1));
        maximum = max(maximum, get_max_score(col+1, 2));
    }
    else if(status == 1){
        maximum = max(get_max_score(col+1, 0), get_max_score(col+1, 2));
    }
    else if(status == 2){
        maximum = max(get_max_score(col+1, 0), get_max_score(col+1, 1));
    }
    result += maximum;
    cache[col][status] = result;
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;

    cin >> T;

    for(int test_case = 0; test_case < T; test_case++){
        memset(sticker, 0, sizeof(sticker));
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
             cin >> sticker[j][i];
            }
        }
        cout << get_max_score(0, 0) << '\n';
    }

    return 0;
}