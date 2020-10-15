#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v;
vector<int> nums;
bool visited[9];
void NandM(){
    if(v.size() == M){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }


    for(int i = 0; i < N; i++){
        if(visited[i]) continue;

        visited[i] = 1;
        v.push_back(nums[i]);
        NandM();
        v.pop_back();
        visited[i] = 0;
    }
    return;
}

int main(){
    cin >> N >> M;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end());

    NandM();
    return 0;
}