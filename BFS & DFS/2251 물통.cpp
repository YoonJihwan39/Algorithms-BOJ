#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

struct Water
{
    int A, B, C;
};


int A, B, C;
bool visited[301][301][301];
bool ans[301];

int main(){
    memset(visited, 0, sizeof(visited));
    memset(ans, 0, sizeof(ans));
    cin >> A >> B >> C;
    visited[0][0][C] = 1;
    ans[C] = 1;
 
    stack<Water> s;
    s.push({0, 0, C});
    while(!s.empty()){
        const Water curr = s.top();
        //cout << curr.A << ' ' << curr.B << ' '<< curr.C << '\n';
        if(curr.A == 0) ans[curr.C] = 1;
        s.pop();

        if(curr.A != 0){
            // pour to B
            if(curr.A <= B - curr.B){
                Water next = {0, curr.B + curr.A, curr.C};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            else {
                Water next = {curr.A - (B - curr.B), B, curr.C};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            // pour to C
            if(curr.A <= C - curr.C){
                Water next = {0, curr.B, curr.C + curr.A};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            else {
                Water next = {curr.A - (C - curr.C), curr.B, C};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
        }
        if(curr.B != 0){
            // pour to A
            if(curr.B <= A - curr.A){
                Water next = {curr.A + curr.B , 0, curr.C};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            else {
                Water next = { A, curr.B - (A - curr.A), curr.C};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            // pour to C
            if(curr.B <= C - curr.C){
                Water next = {curr.A, 0, curr.C + curr.B};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            else {
                Water next = {curr.A, curr.B - (C - curr.C), C};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
        }
        if(curr.C != 0){
            // pour to A
            if(curr.C <= A - curr.A){
                Water next = {curr.A + curr.C , curr.B, 0};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            else {
                Water next = {A, curr.B, curr.C - (A - curr.A)};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            // pour to B
            if(curr.C <= B - curr.B){
                Water next = {curr.A, curr.B + curr.C, 0};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
            else {
                Water next = {curr.A,  B, curr.C - (B - curr.B)};
                if(visited[next.A][next.B][next.C] == 0){
                    s.push(next);
                    visited[next.A][next.B][next.C] = 1;
                } 
            }
        }
    }
    for(int i = 0; i <= C; i++){
        if(ans[i]){
            cout << i << ' ';
        }
    }
    return 0;
}