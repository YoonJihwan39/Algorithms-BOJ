#include<iostream>
using namespace std;

int N, M;
int array[100000];

bool available(int size){
    int blu_num = 1;
    int current_blu_size = 0;
    for(int i = 0; i < N; i++){
        if(array[i] > size){ //강의가 size보다 크다면 바로 false 반환
            return false;
        }
        
        if(current_blu_size + array[i] <= size){ //현재 강의를 넣어서 size보다 작다면 넣음
            current_blu_size += array[i];
        }
        else { //크다면 새로운 bluray에 넣음
            blu_num++;
            current_blu_size = array[i];
        }
    }
    if(blu_num <= M)
        return true;
    else
        return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> array[i];
        sum += array[i];
    }

    int start = sum / M; //모든 강의시간의 합에 블루레이 개수로 나눈것이 최소값
    int end = sum; //모든 강의시간의 합이 최대값
    int mid;
    int result;

    while(start <= end){
        mid = (start + end) / 2;
        if(available(mid)){
            result = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << result;
    return 0;

}