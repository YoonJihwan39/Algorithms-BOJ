//https://twinw.tistory.com/126 참고
#include<iostream>
#include<string>
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

    cout << cache[len1][len2];
    return 0;
}