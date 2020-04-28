#include<iostream>
using namespace std;

int N; 
int array[11];
int largest = -1000000000;
int smallest = 1000000000;
int total_num_of_op[4];

int compute(int a, int op, int b){
    if(op == 0){
        return a + b;
    }
    else if(op == 1){
        return a - b;
    }
    else if(op == 2){
        return a * b;
    }
    else if(op == 3){
        return a / b;
    }
}

void insert_op(int a, int nth, int current_num_of_op[4]){
    if(nth == N-1){
        if(a > largest){
            largest = a;
        }
        if(a < smallest){
            smallest = a;
        }
        return;
    }
    int copy_num_of_op[4];
    for(int i = 0; i < 4; i++){
        copy_num_of_op[i] = current_num_of_op[i];
    }
    for(int i = 0; i < 4; i++){
        if(copy_num_of_op[i] > 0){
            int result = compute(a, i, array[nth+1]);
            copy_num_of_op[i]--;
            insert_op(result, nth+1, copy_num_of_op);
            copy_num_of_op[i]++;
        }
    }
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> total_num_of_op[i];
    }
    insert_op(array[0], 0, total_num_of_op);
    cout << largest << '\n' << smallest;
    return 0;
}