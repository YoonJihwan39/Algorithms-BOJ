#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    string input;
    stack<char> st;
    int result = 0;
    char current_char;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < input.length(); j++){
            current_char = input[j];
            if(st.empty() || current_char != st.top()){
                st.push(current_char);
            }
            else if(current_char == st.top()){
                st.pop();
            }
        }
        if(st.empty()){
            result++;
        }

        while(!st.empty()) st.pop();
    }
    cout << result;
    return 0;
}