#include<iostream>
#include<queue>
using namespace std;

int T;
bool isPrime[10000];
bool visited[10000];

void checkPrime(){
    fill(isPrime, isPrime+10000, 1);

    for(int i = 2; i <= 9999; i++){
        if(isPrime[i] == 0){
            continue;
        }
        for(int j = 2 * i; j <= 9999; j += i){
            isPrime[j] = 0;
        }
    }
    return;
}

int main(){
    cin >> T;
    int input1, input2;
    checkPrime();

    for(int test_case=0; test_case < T; test_case++){
        fill(visited, visited+10000, 0);

        cin >> input1 >> input2;

        queue<pair<int, int>> q;
        q.push(make_pair(input1, 0));
        visited[input1] = 1;
        int result = -1;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            if(curr.first == input2){
                result = curr.second;
                break;
            }
            //1의 자리수 바꾸기
            for(int i = 0; i < 10; i++){
                int next = curr.first - curr.first%10 + i;
                if(isPrime[next] == 1 && visited[next] == 0){
                    visited[next] = 1;
                    q.push(make_pair(next, curr.second+1));
                }
            }
            //10의 자리수 바꾸기
            for(int i = 0; i < 100; i+=10){
                int next = curr.first - curr.first%100 + curr.first%10 + i;
                if(isPrime[next] == 1 && visited[next] == 0){
                    visited[next] = 1;
                    q.push(make_pair(next, curr.second+1));
                }
            }
            //100의 자리수 바꾸기
            for(int i = 0; i < 1000; i+=100){
                int next = curr.first - curr.first%1000 + curr.first%100 + i;
                if(isPrime[next] == 1 && visited[next] == 0){
                    visited[next] = 1;
                    q.push(make_pair(next, curr.second+1));
                }
            }
            //1000의 자리수 바꾸기
            for(int i = 1000; i < 10000; i+=1000){
                int next = curr.first - curr.first/1000*1000 + i;
                if(isPrime[next] == 1 && visited[next] == 0){
                    visited[next] = 1;
                    q.push(make_pair(next, curr.second+1));
                }
            }
        }
        if(result == -1){
            cout << "Impossible\n";
        }
        else {
            cout << result << '\n';
        }
    }
    return 0;
}