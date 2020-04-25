#include<iostream>
#include<vector>
using namespace std;

int N;
vector<pair<int, int>> v;

int job(int day){
    if(day >= N){
        return 0;
    }
    int result = 0;
    // 해당 날짜에 일을 받았을 때
    if(day+v[day].first <= N){
        result = v[day].second + job(day+v[day].first);
    }
    // 일을 받지 않고 다음 날로 갔을 때와 비교하여 큰 것을 return
    result = max(result, job(day+1));
    return result;
}

int main(){
    int result;
    cin >> N;
    for(int i = 0; i < N; i++){
        int T, P;
        cin >> T >> P;
        v.push_back(make_pair(T, P));
    }
    result = job(0);
    cout << result;
    return 0;
}
