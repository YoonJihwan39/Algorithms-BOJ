#include<iostream>
using namespace std;

int result[3] = {0, 0, 0};
int paper[2187][2187];
int N;

void find_paper(int begin_x, int begin_y, int end_x, int end_y){
    //크기가 1짜리면 종이 개수에 추가
    if(begin_x == end_x && begin_y == end_y){
        result[paper[begin_y][begin_x]+1]++;
        return;
    }
    int i, j;
    int check = paper[begin_y][begin_x];
    bool usable = true;
    //현재 종이가 1개의 종류로 되어있는지 확인
    for(i = begin_y; i <= end_y; i++){
        for(j = begin_x; j <= end_x; j++){
            if(paper[i][j] != check){
                usable = false;
                break;
            }
        }
        if(usable == false){
                break;
        }
    }
    if(usable){
        result[check+1]++;
        return;
    }
    //같은 크기 9개로 나누기
    int length = end_x - begin_x + 1;
    int interval = length / 3;
    for(i = begin_y; i <= end_y; i+=interval){
        for(j = begin_x; j <= end_x; j+=interval){
            find_paper(j, i, j + interval - 1, i + interval - 1);
        }
    }
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
    find_paper(0, 0, N-1, N-1);
    for(int i = 0; i < 3; i++){
        cout << result[i] << '\n';
    }
    return 0;
}