#include<iostream>
#include<queue>
#include<string>
#include<set>
using namespace std;

struct Situation
{
    string puzzle;
    int pos, cnt;
};


set<string> visited;
string puzzle = "";
char input;
int start_point;
//위, 왼쪽, 오른쪽, 아래로 이동
int dpos[4] = {-3, -1, 1, 3};

int bfs(){
    queue<Situation> q;
    Situation start = {puzzle, start_point, 0};
    q.push(start);
    visited.insert(puzzle);
    while(!q.empty()){
        Situation current = q.front();
        q.pop();
        if(current.puzzle == "123456780") return current.cnt;
        for(int i = 0; i < 4; i++){
            //3번째 column일 경우 오른쪽으로 이동 불가
            if(current.pos % 3 == 2 && i == 2) continue;
            //1번째 column일 경우 왼쪽쪽으로 이동 불가
            if(current.pos % 3 == 0 && i == 1) continue;

            int new_position = current.pos + dpos[i];
            //배열을 벗어나게 이동 불가
            if(new_position < 0 || new_position >= 9) continue;
            
            string new_puzzle = current.puzzle;
            //swap
            char temp = new_puzzle[current.pos];
            new_puzzle[current.pos] = new_puzzle[new_position];
            new_puzzle[new_position] = temp;
            //해당 퍼즐이 처음이라면(set에 없다면) push
            if(visited.find(new_puzzle) == visited.end()){
                q.push({new_puzzle, new_position, current.cnt+1});
                visited.insert(new_puzzle);
            }
        }
    }
    return -1;
}

int main(){
    for(int i = 0; i < 9; i++){
        cin >> input;
        puzzle += input;
        if(input == '0'){
            start_point = i;
        }
    }
    cout << bfs();
    return 0;
}
