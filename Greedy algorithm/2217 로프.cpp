#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int *array, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = start;
    int i = pivot+1;
    int j = end;

    while(i <= j){
        while(i <= end && array[i] >= array[pivot]){
            i++;
        }
        while(j > start && array[j] <= array[pivot]){
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

int main(){
    int N;

    cin >> N;

    int rope[N];
    int cnt = 0;
    int weight = 0;

    for(int i = 0; i < N; i++){
        cin >> rope[i];
    }

    quick_sort(rope, 0, N-1); //내림차순 정렬

    //greedy algorithm 사용: 최적값에는 중량 제한이 큰 로프가 무조건 들어가므로
    for(int i = 0; i < N; i++){
        cnt++;
        int temp = rope[i] * cnt;
        if(weight < temp){
            weight = temp;
        }
    }
    cout << weight;
}

