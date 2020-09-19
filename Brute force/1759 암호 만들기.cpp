// http://kks227.blog.me/220786417910 참고
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int L, C;
vector<char> v;
char PW[16];
int isVowel[26];

void bt(int pos, int prev, int consonant, int vowel){
    if(pos == L){
        if(consonant >= 2 && vowel >= 1){
            cout << PW << '\n';
        }
        return;
    }
    for(int i = prev+1; i < C; i++){
        PW[pos] = v[i];
        if(isVowel[v[i]-'a']){
            bt(pos+1, i, consonant, vowel+1);
        }
        else {
            bt(pos+1, i, consonant+1, vowel);
        }
    }
    return;
}

int main(){
    cin >> L >> C;
    char input;
    for(int i = 0; i < C; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    //모음 표시
    isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
    bt(0, -1, 0, 0);
    return 0;
}