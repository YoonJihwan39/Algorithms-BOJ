#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n;
vector<int> wine;
int cache[10000];

//n번째 와인에서  최대로 마실 수 있는 와인의 양을 return
int DP(int nth){
    if(nth >= n) return 0;
    if(cache[nth] != -1) return cache[nth];
    
    int result = 0;
    if(nth <= n-2){
        //n번째 와인을 마시고 n+1번째 와인도 마셨을 경우
        result = max(result, wine[nth] + wine[nth+1] + DP(nth+3));
    }
    //n번째 와인을 마시고 n+1번째 와인을 마시지 않은 경우
    result = max(result, wine[nth] + DP(nth+2));
    //n번째 와인을  마시지 않았을 때
    result = max(result, DP(nth+1));
    
    cache[nth] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> n;
    int input;
    for(int i = 0; i < n; i++){
        cin >> input;
        wine.push_back(input);
    }
    cout << DP(0);
    return 0;
}