#include<iostream>
#include<stack>
using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, P;
    int input_line, input_fret;
    int movement = 0;
    cin >> N >> P;

    stack<int> line[7];

    for(int i = 0; i < N; i++){
        cin >> input_line >> input_fret;
        
        //해당 줄의 stack이 비거나 낮거나 같은 fret이 나올 때까지 손가락을 땜.
        while(!line[input_line].empty() && input_fret < line[input_line].top()){
            line[input_line].pop();
            movement++;
        }
        //같은 줄의 같은 프렛이면 손가락 움직일 필요 없음
        if(!line[input_line].empty() && input_fret == line[input_line].top()){
            continue;
        }
        //다른 프렛이면 해당 프렛을 누름.
        else {
            line[input_line].push(input_fret);
            movement++;
        }
    }
    cout << movement;
    return 0;
}