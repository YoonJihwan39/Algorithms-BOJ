#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, C;
vector<int> house;

bool available(int distance){
    int count = 1;
    int pivot = house[0];
    for(int i = 1; i < N; i++){
        if(house[i] - pivot >= distance){
            count++;
            pivot= house[i];
        }
    }

    if(count >= C){
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        house.push_back(input);
    }

    sort(house.begin(), house.end());

    int start = 1;
    int end = house.back() - house.front();
    int mid = (start + end) / 2;
    int result;

    while(start <= end){
        if(available(mid)){
            result = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }

    cout << result;
    return 0;
}