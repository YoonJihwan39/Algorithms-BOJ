#include <iostream>
using namespace std;

void quick_sort(int *array, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = start;
    int i = pivot+1;
    int j = end;

    while(i <= j){
        while(i <= end && array[i] <= array[pivot]){
            i++;
        }
        while(j > start && array[j] >= array[pivot]){
            j--;
        }

        if(i > j){
            int temp = array[pivot];
            array[pivot] = array[j];
            array[j] = temp;
        }
        else{
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    quick_sort(array, start, j - 1);
    quick_sort(array, j + 1, end);

    return;
}

int main() {
    int N;
    
    int time = 0;

    cin >> N;

    int P[N];

    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    //입력 완료

    //시간이 적게 걸리는 사람이 먼저 할수록 기다리는 시간이 줄어듬
    quick_sort(P, 0, N-1);

    for(int i = 0; i < N; i++){
        time = time + P[i] * (N - i);
    }
    cout << time;
    return 0;

}