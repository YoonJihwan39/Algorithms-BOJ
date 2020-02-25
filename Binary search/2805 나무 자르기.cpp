#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<int> height;

bool available(int saw){
    long long count = 0;
    for(int i = 0; i < N; i++){
        if(height[i] > saw){
            count += height[i] - saw;
        }
    }

    if(count >= M){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        height.push_back(input);
    }

    sort(height.begin(), height.end());

    int start = 0;
    int end = height.back();
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