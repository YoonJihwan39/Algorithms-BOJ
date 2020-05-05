#include<iostream>
#include<vector>
using namespace std;

int N, M;
int map[50][50];
int chicken_distance[100][13]; //각 집에서 각 치킨 가게까지의 거리
vector<pair<int, int>> house;
vector<pair<int, int>> store;
int result = 987654321;

void choose_M(int nth, vector<int> choosed_store){
    if(nth == store.size()){
        if(choosed_store.size() == M){
            int town_chicken_distance = 0;
            //각 집에서 M개의 가게까지의 거리의 최소값을 구함
            for(int i = 0; i < house.size(); i++){
                int smallest = 987654321;
                for(int j = 0; j < choosed_store.size(); j++){
                    smallest = min(smallest, chicken_distance[i][choosed_store[j]]);
                }
                // 집의 치킨거리를 마을 치킨 거리에 더해줌
                town_chicken_distance += smallest;
            }
            result = min(result, town_chicken_distance);
        }
        return;
    }
    
    //해당 n번째 가게를 포함시킬 때(선택한 것이 M개보다 작아야 넣을 수 있음)
    if(choosed_store.size() < M){
        choosed_store.push_back(nth);
        choose_M(nth+1, choosed_store);
        choosed_store.pop_back();
    }
    //해당 n번째 가게를 포함시키지 않을 때
    choose_M(nth+1, choosed_store);
    return;
    
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                house.push_back(make_pair(i, j));
            }
            else if(map[i][j] == 2){
                store.push_back(make_pair(i, j));
            }
        }
    }
    // 각 집에서 각 치킨 가게까지의 거리 구하기
    for(int i = 0; i < house.size(); i++){
        for(int j = 0; j < store.size(); j++){
            int height = (house[i].first > store[j].first) ? house[i].first - store[j].first : store[j].first - house[i].first;
            int weight = (house[i].second > store[j].second) ? house[i].second - store[j].second : store[j].second - house[i].second;
            chicken_distance[i][j] = height + weight;
        }
    }
    vector<int> v;
    choose_M(0, v);
    cout << result;
    return 0;
}