#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> homework;
bool day_occupied[1001];
int N;

bool desc(pair<int, int> a, pair<int, int> b){
    return a > b;
}

int main(){
    int d, w;
    int finish;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> d >> w;
        homework.push_back(make_pair(w, d));
    }
    //점수 내림차순
    sort(homework.begin(), homework.end(), desc);

    int current, day = 0, result = 0;

    for(int i = 0; i < N; i++){
        //가장 늦게 끝낼 수 있는 날을 찾을 수 있으면 포함시킴
        finish = homework[i].second;
        while(finish >= 0 && day_occupied[finish] == 1){
            finish--;
        }
        if(finish > 0){
            day_occupied[finish] = 1;
            result += homework[i].first;
        }
    }

    cout << result;
    return 0;
}