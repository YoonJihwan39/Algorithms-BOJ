#include<iostream>
#include<list>
using namespace std;

int N, K;
bool used[26];

int main(){
    cin >> N >> K;
    list<char> wheel;
    for(int i = 0; i < N; i++){
        wheel.push_back('?');
    }
    int change;
    char letter;
    bool exist = 1;
    for(int i = 0; i < K; i++){
        cin >> change >> letter;
        //change만큼 뒤에 것을 앞으로 이동
        for(int j = 0; j < change; j++){
            int back = wheel.back();
            wheel.pop_back();
            wheel.push_front(back);
        }
        if((wheel.front() == '?' && used[letter-'A'] == 0) || wheel.front() == letter){
            wheel.pop_front();
            wheel.push_front(letter);
            used[letter-'A'] = 1;
        }
        else{
            exist = 0;
            break;
        }
    }

    if(exist){
        while(!wheel.empty()){
            cout << wheel.front();
            wheel.pop_front();
        }
    }
    else{
        cout << '!';
    }
    
    return 0;
}