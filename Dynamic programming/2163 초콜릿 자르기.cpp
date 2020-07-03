#include<iostream>
using namespace std;

int N, M;
int cache[301][301];

//nxm을 1x1로 만들기 위한 최소 쪼개기 횟수 return
int DynamicProgramming(int n, int m){
    if(n == 1 && m == 1){
        return 0;
    }
    if(cache[n][m] != 0){
        return cache[n][m];
    }
    int result = 987654321;
    //1~n-1의 눈금 중에 하나를 선택해서 가로로 자름
    for(int i = 1; i <= n-1; i++){
        result = min(result, 1 + DynamicProgramming(i, m) + DynamicProgramming(n-i, m));
    }
    //1~m-1의 눈금 중에 하나를 선택해서 세로로 자름
    for(int i = 1; i <= m-1; i++){
        result = min(result, 1 + DynamicProgramming(n, i) + DynamicProgramming(n, m-i));
    }
    cache[n][m] = result;
    return result;
}

int main(){
    cin >> N >> M;
    cout << DynamicProgramming(N, M);
    return 0;
}