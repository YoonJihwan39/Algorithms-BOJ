#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> A;

int main(){
    cin >> N >> M;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        A.push_back(input);   
    }
    //오름차순으로 정렬
    sort(A.begin(), A.end());

    int s = 0, e = 0;
    int diff = A[e] - A[s];
    int result = 2000000001;

    if(diff >= M){
        result = min(result, diff);
    }
    while(1){
        //차이가 M보다 크면 s를 한 칸 오른쪽으로
        if(diff > M){
            diff = diff + A[s] - A[++s];
        }
        else if(e == N-1) break;
        
        else {
            diff = diff - A[e] + A[++e];
        }

        if(diff >= M){
            result = min(result, diff);
            if(result == M){
                break;
            }
        }
    }
    cout << result;
    return 0;
}