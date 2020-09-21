#include<iostream>
#include<vector>
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

    int result = 0;
    int s = 0, e = 0;
    int sum = 0;
    while(1){
        if(sum >= M){
            sum -= A[s];
            s++;
        }
        else if(e == N){
            break;
        }
        else {
            sum += A[e];
            e++;
        }

        if(sum == M){
            result++;
        }
    }
    cout << result;
    return 0;
}