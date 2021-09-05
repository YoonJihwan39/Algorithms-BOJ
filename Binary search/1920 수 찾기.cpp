#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int A[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    cin >> M;
    for(int i = 0; i < M; i++){
        int input;
        cin >> input;
        int start = 0;
        int finish = N - 1;
        int mid;
        bool found = 0;
        while(start <= finish){
            mid = (start + finish) / 2;
            if(A[mid] == input){
                found = 1;
                break;
            }
            else if(input > A[mid]){
                start = mid + 1;
            }
            else{
                finish = mid - 1;
            }
        }
        cout << found << '\n';
    }
    return 0;
}