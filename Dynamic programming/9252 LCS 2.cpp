// https://www.crocus.co.kr/787 참고
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int cache[1001][1001];
string str1;
string str2;

int main(){
    cin >> str1;
    cin >> str2;
    int len1 = str1.length();
    int len2 = str2.length();

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(str1[i] == str2[j]){
                cache[i+1][j+1] = cache[i][j] + 1;
            }
            else {
                cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
            }
        }
    }

    cout << cache[len1][len2] << '\n';

    int i = len1;
    int j = len2;
    stack<char> lcsStack;
    while(cache[i][j] != 0){
        if(cache[i][j] == cache[i-1][j]) i--;
        else if(cache[i][j] == cache[i][j-1]) j--;
        else if(cache[i][j] - 1 == cache[i-1][j-1]){
            lcsStack.push(str1[i-1]);
            i--;
            j--;
        }
    }

    while(!lcsStack.empty()){
        cout << lcsStack.top();
        lcsStack.pop();
    }

    return 0;
}