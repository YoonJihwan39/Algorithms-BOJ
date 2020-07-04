// https://hsp1116.tistory.com/23 참고
#include<iostream>
#include<string.h>
using namespace std;

int n, k;
int value[100];
int cache[10001];

int main(){
    memset(cache, 0, sizeof(cache));
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    cache[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(j >= value[i]){
                cache[j] += cache[j-value[i]];
            }
        }
    }
    cout << cache[k];
    return 0;
}