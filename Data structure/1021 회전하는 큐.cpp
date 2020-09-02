#include<iostream>
#include<list>
using namespace std;

int move_left(list<int> l, int loc){
    int front;
    int back;
    int cnt = 0;
    for(int i = 0; i < l.size(); i++){
        front = l.front();
        l.pop_front();
        l.push_back(front);
        cnt++;
        if(l.front() == loc){
            return cnt;
        }
    }

}

int move_right(list<int> l, int loc){
    int back;
    int front;
    int cnt = 0;
    for(int i = 0; i < l.size(); i++){
        back = l.back();
        l.pop_back();
        l.push_front(back);
        cnt++;
        if(l.front() == loc){
            return cnt;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    // 길이 N인 리스트 생성
    list<int> l;
    for(int i = 1; i <= N; i++){
        l.push_back(i);
    }
    int loc;
    int left, right;
    int result = 0;
    for(int i = 0; i < M; i++){
        cin >> loc;
        if(l.front() == loc){
            l.pop_front();
            continue;
        }
        left = move_left(l, loc);
        right = move_right(l, loc);
        if(left <= right){
            for(int j = 0; j < left; j++){
                int front = l.front();
                l.pop_front();
                l.push_back(front);
            }
            result += left;
        }
        else {
            for(int j = 0; j < right; j++){
                int back = l.back();
                l.pop_back();
                l.push_front(back);
            }
            result += right;
        }
        l.pop_front();
    }
    cout << result;
    return 0;
}