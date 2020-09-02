#include<iostream>
#include<list>
using namespace std;

int N, K;
list<int> l;

int main(){
    cin >> N >> K;
    cout << '<';
    for(int i = 1; i <= N; i++){
        l.push_back(i);
    }
    while(!l.empty()){
        for(int i = 0; i < K-1; i++){
            int front = l.front();
            l.pop_front();
            l.push_back(front);
        }
        cout << l.front();
        l.pop_front();
        if(l.empty()){
            cout << '>';
        }
        else {
            cout << ", ";
        }
    }
    return 0;
}