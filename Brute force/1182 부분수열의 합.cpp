#include<iostream>
using namespace std;

int array[20];
int N, S;
int count = 0;

void subarray_sum (int pos, int sum, int size){
    if(pos == N){
        if(sum == S && size != 0) {
            count++;
        }
        return;
    }
    //해당 위치의 원소를 수열에 포함시켰을 때
    subarray_sum(pos+1, sum+array[pos], size+1);

    //해당 위치의 원소를 수열에 포함시키지 않았을 때
    subarray_sum(pos+1, sum, size);

    return;
}

int main(){
    cin >> N >> S;

    for(int i = 0; i < N; i++){
        cin >> array[i];
    }

    subarray_sum(0, 0, 0);

    cout << count;
    return 0;

}