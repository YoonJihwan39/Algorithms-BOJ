#include<iostream>
#include<cstring>
using namespace std;

int n, k;
int value[101];
int cache[10001];
// left 금액을 맞출 수 있는 동전의 최소 개수 return
int get_min_num (int left){
    //left가 0이면 재귀종료
    if(left == 0){
        return 0;
    }
    //left가 음수인 경우 불가능한 경우이므로 매우 큰 값 반환
    else if(left < 0){
        return 987654321;
    }

    if(cache[left] != -1){
        return cache[left];
    }

    int result = 987654321;
    // 현재 left에서 각 동전을 사용한 경우 중 가장 작은 결과값을 출력
    for(int i = 1; i <= n; i++){
        result = min(result, 1 + get_min_num(left - value[i]));
    }
    cache[left] = result;
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    for(int i = 1; i <= n; i++){
        cin >> value[i];
    }
    int result = get_min_num(k);
    //최대 동전의 개수는 10000이므로 이보다 크면 불가능으로 간주.
    if(result > 10000){
        cout << -1;
    }
    else {
        cout << result;
    }
    return 0;
}