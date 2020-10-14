#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v;
bool visited[9];

void NandM(){
    if(v.size() == M){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        if(visited[i] == 1) continue;

        visited[i] = 1;
        v.push_back(i);
        NandM();
        visited[i] = 0;
        v.pop_back();
    }
    return;
}

int main(){
    cin >> N >> M;
    NandM();
    return 0;
}