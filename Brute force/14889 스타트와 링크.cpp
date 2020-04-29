#include<iostream>
#include<vector>
using namespace std;

int N;
int S[20][20];
int minimum = 987654321;

int compute_difference_of_ability(vector<int> start, vector<int> link){
    int start_ability = 0, link_ability = 0;
    for(int i = 0; i < N / 2; i++){
        for(int j = 0; j < N / 2; j++){
            start_ability += S[start[i]][start[j]];
        }
    }

    for(int i = 0; i < N / 2; i++){
        for(int j = 0; j < N / 2; j++){
            link_ability += S[link[i]][link[j]];
        }
    }
    int result = start_ability - link_ability;
    return (result >=0) ? result : (result * -1);
}

void divide_team(int nth, vector<int> start, vector<int> link){
    if(nth == N){
        int result = compute_difference_of_ability(start, link);
        minimum = min(minimum, result);
        return;
    }
    // start 팀이 비어있다면 넣고 재귀
    if(start.size() < N / 2){
        start.push_back(nth);
        divide_team(nth+1, start, link);
        start.pop_back();
    }
    // link 팀이 비어있다면 넣고 재귀
    if(link.size() < N / 2){
        link.push_back(nth);
        divide_team(nth+1, start, link);
        link.pop_back();
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> S[i][j];
        }
    }
    vector<int> s, l;
    divide_team(0, s, l);
    cout << minimum;
    return 0;
}