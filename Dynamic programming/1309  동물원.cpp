#include <iostream>
using namespace std;

int N;
int cache[100001][3];

int DP(int pos, int status){
    if(pos == 1){
        return 1;
    }
    if(cache[pos][status] != -1){
        return cache[pos][status];
    }

    int result = 0;
    if(status == 0){
        result = (DP(pos-1, 0) + DP(pos -1, 1) + DP(pos -1, 2));
    }
    else if(status == 1){
        result = (DP(pos-1, 0) + DP(pos -1, 2));
    }
    else {
        result = (DP(pos-1, 0) + DP(pos -1, 1));
    }
    result %= 9901;
    cache[pos][status] = result;
    return result;
}

int main(){
    for(int i = 0; i < 100001; i++){
        cache[i][0] = -1;
        cache[i][1] = -1;
        cache[i][2] = -1;
    }
    cin >> N;
    cout << (DP(N, 0) + DP(N, 1) + DP(N, 2)) % 9901 << '\n';
    return 0;
}