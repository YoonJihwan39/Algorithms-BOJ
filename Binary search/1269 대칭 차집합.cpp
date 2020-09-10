#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A, B;
vector<int> setA;
vector<int> setB;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    int input;
    for(int i = 0; i < A; i++){
        cin >> input;
        setA.push_back(input);
    }
    for(int i = 0; i < B; i++){
        cin >> input;
        setB.push_back(input);
    }
    sort(setB.begin(), setB.end());
    //겹치는 원소의 수X2를 A+B와 빼면 원하는 결과가 나옴
    //A를 기준으로 B와 겹치는 원소 구하기
    int cnt = 0;
    for(int i = 0; i < A; i++){
        int start = 0;
        int finish = B-1;
        int middle;
        while(start <= finish){
            middle = (start + finish) / 2;
            if(setB[middle] == setA[i]){
                cnt++;
                break;
            }
            else if(setB[middle] < setA[i]){
                start = middle+1;
            }
            else {
                finish = middle-1;
            }
        }
    }

    cout << A + B - 2 * cnt;
    return 0;
}