#include<iostream>
#include<cstring>
using namespace std;

int N;
int A[1000];
int cache[1000];
//배열의 x번째 원소에서 가장 큰 증가 부분 수열 합을 return
int largest_ascending_sequence(int x){
    if(x == N-1){
        return A[x];
    }
    if(cache[x] != -1){
        return cache[x];
    }
    int result = A[x];
    //A[x]보다 큰 원소가 있으면 재귀호출
    for(int i = x+1; i < N; i++){
        if(A[i] > A[x]){
            result = max(result, A[x] + largest_ascending_sequence(i));
        }
    }
    cache[x] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int result = 0;
    for(int i = 0; i < N; i++){
        result = max(result, largest_ascending_sequence(i));
    }
    cout << result;
    return 0;
}