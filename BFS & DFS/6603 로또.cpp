#include<iostream>
#include<vector>
using namespace std;

int k;
int S[12];

void dfs(int n, vector<int> v){
    if(v.size() == 6){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else if(n == k){
        return;
    }

    //n번째를 포함했을 때
    v.push_back(S[n]);
    dfs(n+1, v);
    //n번째를 포함하지 않았을 때
    v.pop_back();
    dfs(n+1, v);
    return;
}

int main(){
    while(1){
        cin >> k;
        if(k == 0){
            break;
        }
        for(int i = 0; i < k; i++){
            cin >> S[i];
        }
        vector<int> v;
        dfs(0, v);
        cout << '\n';
    }
    return 0;
}