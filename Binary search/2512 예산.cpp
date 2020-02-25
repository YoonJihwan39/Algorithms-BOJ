#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<int> budget;

bool available(int limit){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(budget[i] <= limit){
            count += budget[i];
        }
        else {
            count += limit;
        }
    }
    if(count <= M){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int input;

    for(int i = 0; i < N; i++){
        cin >> input;
        budget.push_back(input);
    }
    cin >> M;
    // 예산 오름차순 정렬
    sort(budget.begin(), budget.end());

    int start = 0;
    int end = budget.back();
    int mid;
    int result;

    while(start <= end){
        mid = (start + end) / 2;
        if(available(mid)){
            result = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << result;
    return 0;
}