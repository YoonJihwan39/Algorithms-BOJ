#include<iostream>
#include<list>
#include<string>
using namespace std;

string input;
list<pair<int, char>> str;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    str.push_back(make_pair(0, ' '));
    cin >> input;
    int id = input.length();
    int lastCharNum = id;
    for(int i = 1; i <= input.length(); i++){
        str.push_back(make_pair(i, input[i-1]));
    }
    //커서를 맨 뒤로 이동
    for(int i = 0; i < input.length(); i++){
        pair<int, char> front = str.front();
        str.pop_front();
        str.push_back(front);
    }
    int M;
    cin >> M;
    char cmd;
    for(int i = 0; i < M; i++){
        cin >> cmd;
        if(cmd == 'P'){
            id++;
            // 만약 맨 오른쪽이면 lastCharNum을 지금 추가한 id로 변경
            if(str.front().first == lastCharNum){
                lastCharNum = id;
            }
            char var;
            cin >> var;
            pair<int, char> front = str.front();
            str.pop_front();
            str.push_back(front);
            str.push_front(make_pair(id, var));
        }
        else if(cmd == 'L' && str.front().first != 0){
            pair<int, char> back = str.back();
            str.pop_back();
            str.push_front(back);
        }
        else if(cmd == 'D' && str.front().first != lastCharNum){
            pair<int, char> front = str.front();
            str.pop_front();
            str.push_back(front);
        }
        else if(cmd == 'B' && str.front().first != 0){
            if(str.front().first == lastCharNum){
                lastCharNum = str.back().first;
            }
            str.pop_front();
            pair<int, char> back = str.back();
            str.pop_back();
            str.push_front(back);
        }
    }

    //문자열의 처음을 찾아서 출력
    for(int i = 0; i < str.size(); i++){
        if(str.front().first == 0){
            break;
        }
        pair<int, char> front = str.front();
        str.pop_front();
        str.push_back(front);
    }
    str.pop_front();
    while(!str.empty()){
        cout<< str.front().second;
        str.pop_front();
    }
    return 0;
}