#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> network(101);
bool visited[101];
queue<int> q;

int main(){
    int com, con;
    cin >> com >> con;
    int input1, input2;
    for(int i = 0; i < con; i++){
        cin >> input1 >> input2;
        network[input1].push_back(input2);
        network[input2].push_back(input1);
    }

    visited[1] = 1;
    int result = 0;
    q.push(1);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0; i < network[current].size(); i++){
            if(visited[network[current][i]] == 0){
                result++;
                visited[network[current][i]] = 1;
                q.push(network[current][i]);
            }
        }
    }
    cout << result;
    return 0;
}