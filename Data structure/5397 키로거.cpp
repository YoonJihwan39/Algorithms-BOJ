#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int test_case = 0; test_case < T; test_case++){
        string L;
        cin >> L;

        list<pair<int, char>> input;
        input.push_back(make_pair(0, ' '));
        int ID = 0;
        int lastID = 0;
        
        for(int i = 0; i < L.length(); i++){
            char cmd = L[i];

            if(cmd == '<'){
                if(input.front().first == 0){
                    continue;
                }
                pair<int, char> back = input.back();
                input.pop_back();
                input.push_front(back);
            }
            else if(cmd == '>'){
                if(input.front().first == lastID){
                    continue;
                }
                pair<int, char> front = input.front();
                input.pop_front();
                input.push_back(front);
            }
            else if(cmd == '-'){
                if(input.front().first == 0){
                    continue;
                }
                //만약 마지막 문자를 삭제했다면 그 앞의 문자가 마지막 문자가 됨.
                if(input.front().first == lastID){
                    lastID = input.back().first;
                }
                input.pop_front();
                pair<int, char> back = input.back();
                input.pop_back();
                input.push_front(back);
            }
            else {
                ID++;
                //줄의 마지막에 추가하려는 경우 마지막 문자를 새로 추가한 문자로 바꿔줌.
                if(input.front().first == lastID){
                    lastID = ID;
                }

                pair<int, char> front = input.front();
                input.pop_front();
                input.push_back(front);

                input.push_front(make_pair(ID, cmd));
            }
        }

        //줄의 시작을 찾음
        for(int i = 0; i < input.size(); i++){
            if(input.front().first == 0){
                break;
            }
            pair<int, char> front = input.front();
            input.pop_front();
            input.push_back(front);
        }

        input.pop_front();

        while(!input.empty()){
            cout << input.front().second;
            input.pop_front();
        }
        cout << '\n';
    }
    return 0;
}
