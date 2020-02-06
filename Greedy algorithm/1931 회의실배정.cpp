#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int begin, end;
    int count = 0;
    int time = 0;
    cin >> N;
    vector<pair<int, int>> meeting(N);
    for(int i = 0; i < N; i++){
        cin >> begin >> end;
        meeting[i].first = end;
        meeting[i].second = begin;
    }
    sort(meeting.begin(), meeting.end()); //끝나는 순서대로 정렬

    for(int i = 0; i < N; i++){
        if(time <= meeting[i].second){  
            time = meeting[i].first;
            count++;
        }
    }

    cout << count;
    return 0;


}