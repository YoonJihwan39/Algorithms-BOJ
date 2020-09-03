#include<iostream>
#include<list>
using namespace std;

int N;
list<pair<int, int>> balloon;

int main(){
    cin >> N;
    int input;
    for(int i = 1; i <= N; i++){
        cin >> input;
        balloon.push_back(make_pair(i, input));
    }

    while(!balloon.empty()){
        cout << balloon.front().first << ' ';
        int num = balloon.front().second;
        balloon.pop_front();
        if(balloon.empty()){
            break;
        }
        // 적힌 숫자가 양수일 때
        if(num > 0){
            for(int i = 0; i < num-1; i++){
                pair<int, int> front = balloon.front();
                balloon.pop_front();
                balloon.push_back(front);
            }
        }
        else{
            num *= -1;
            for(int i = 0; i < num; i++){
                pair<int, int> back = balloon.back();
                balloon.pop_back();
                balloon.push_front(back);
            }
        }
    }
}