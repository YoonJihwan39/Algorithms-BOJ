#include<iostream>
using namespace std;

int T, n;
int cache[11];

//num을 1, 2, 3의 합으로 나타낼 수 있는 개수를 return
int DynamicProgramming(int num){
    if(cache[num] != 0){
        return cache[num];
    }
    int result = 0;
    //1을 하나 썼을 때
    if(num >= 1){
        result += DynamicProgramming(num-1);
    }
    //2를 하나 썼을 때
    if(num >= 2){
        result +=  DynamicProgramming(num-2);
    }
    //3을 하나 썼을 때
    if(num >= 3){
        result +=  DynamicProgramming(num-3);
    }
    cache[num] = result;
    return result;
}

int main(){
    cin >> T;
    cache[0] = 1;
    cache[1] = 1;
    for(int test_case = 0; test_case < T; test_case++){
        cin >> n;
        cout <<DynamicProgramming(n) << '\n';
    }
    return 0;
}