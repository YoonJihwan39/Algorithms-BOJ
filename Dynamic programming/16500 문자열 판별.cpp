#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string S;
int N;
string A[100];
int cache[101];

//문자열 S의 start부터 끝까지 S와 같은 문자열을 만들 수 있다면 true반환, 만들 수 없으면 false 반환
bool check_string (int start){
    if(start == S.length()){
        return true;
    }
    if(cache[start] != -1){
        return cache[start];
    }
    bool result = false;
    //start부터 각 A의 길이만큼 자른 문자열 S와 A를 비교하여 같다면 재귀호출
    for(int i = 0; i < N; i++){
        if(S.substr(start, A[i].length()) == A[i]){
            result = check_string(start+A[i].length());
            if(result){
                break;
            }
        }
    }
    cache[start] = result;
    return result;
}
int main(){
    memset(cache, -1, sizeof(cache));
    cin >> S;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cout << check_string(0);
    return 0;
}