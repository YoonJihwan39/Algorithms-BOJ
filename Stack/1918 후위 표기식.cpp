//참고 http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220781557098&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList 
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool is_current_higher (char current, char top){
    if((current == '*' || current == '/') && (top == '+' || top == '-')){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    
    string input;
    cin >> input;
    char current_char;
    stack<char> op;

    for(int i = 0; i < input.length(); i++){
        current_char = input[i];
        if(current_char >= 'A' && current_char <= 'Z'){
            cout << current_char;
        }
        else if(current_char == '('){
            op.push('(');
        }
        else if(current_char == ')'){
            while(op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.pop();
        }
        else if(current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/'){
            while(!op.empty() && op.top() != '(' && !is_current_higher(current_char, op.top())){
                cout << op.top();
                op.pop();
            }
            op.push(current_char);
        }
    }
    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
    return 0;
}