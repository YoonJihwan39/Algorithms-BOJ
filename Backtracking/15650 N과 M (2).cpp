#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> v;

void NandM(){
    if(v.size() == M){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }


    for(int i = v.empty()? 1 : v.back()+1; i <= N; i++){
        v.push_back(i);
        NandM();
        v.pop_back();
    }
    return;
}

int main(){
    cin >> N >> M;

    NandM();
    return 0;
}