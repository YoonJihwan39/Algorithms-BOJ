#include<iostream>
#include<vector>
using namespace std;

vector<int> PRIME;
int N;

void prime(int num){
    bool arr[num+1];
    fill(arr, arr+num+1, 1);

    for(int i = 2; i <= num; i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = 2 * i; j <= num; j += i){
            arr[j] = 0;
        }
    }

    for(int i = 2; i <= num; i++){
        if(arr[i]){
            PRIME.push_back(i);
        }
    }
    return;
}

int main(){
    cin >> N;
    prime(N);

    int result = 0;
    int sum = 0;
    int s = 0, e = 0;
    while(1){
        if(sum >= N){
            sum -= PRIME[s];
            s++;
        }
        else if(e == PRIME.size()) break;
        else{
            sum += PRIME[e];
            e++;
        }

        if(sum == N) result++;
    }
    cout << result;
    return 0;
}