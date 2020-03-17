#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, K;
vector<pair<int, int>> item;
int cache[100][100001];

//item_num번째 아이템과 현재 무게가 주어졌을 때 최대 가치 반환
int package (int item_num, int current_weight){
    //현재 무게가 K를 넘어가면 큰 음수를 반환하여 선택하지 않도록 함.
    if(current_weight > K){
        return -987654321;
    }
    if(item_num >= N){
        return 0;
    }
    if(cache[item_num][current_weight] != -1){
        return cache[item_num][current_weight];
    }
    //현재 아이템을 포함시켰을 때
    int include = item[item_num].second + package(item_num+1, current_weight+item[item_num].first);
    //현재 아이템을 제외시켰을 때
    int exclude = package(item_num+1, current_weight);
    int result = max(include, exclude);
    cache[item_num][current_weight] = result;
    return result;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    int weight, value;
    for(int i = 0; i < N; i++){
        cin >> weight >> value;
        item.push_back(make_pair(weight, value));
    }
    cout << package(0, 0);
    return 0;
}