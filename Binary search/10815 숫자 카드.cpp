#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int own[500000];
int check;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> own[i];
    }
    cin >> M;
    //오름차순 정렬
    sort(own, own + N);
    for(int i = 0; i < M; i++){
        cin >> check;
        
        int start = 0;
        int finish = N;
        int middle;
        bool exist = 0;
        while(start <= finish){
            middle = (start + finish) / 2;
            if(check == own[middle]){
                exist = 1;
                break;
            }
            else if(check < own[middle]){
                finish = middle-1;
            }
            else{
                start = middle+1;
            }
        }
        cout << exist << " ";
    }
    return 0;
}