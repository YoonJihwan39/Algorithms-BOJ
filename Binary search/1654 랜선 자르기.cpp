#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int K, N;
vector<long long> length;

bool available (long long len){
    int num = 0;

    for(int i = K-1; i >= 0; i--){
        num = num + (length[i] / len);
        if(num >= N){
            return true;
        }
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long input;

    cin >> K >> N;

    for(int i = 0; i < K; i++){
        cin >> input;
        length.push_back(input);
    }

    sort(length.begin(), length.end()); //길이에 따라 오름차순 정렬

    

    //binary search
    long long start = 1;
    long long end = length[K-1];
    long long mid = (start + end) / 2;
    long long result = 0;

    while(start <= end){
        if(available(mid)){
            if(mid > result){
                result = mid;
            }
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