#include<iostream>
#include<stack>
#include<string>
using namespace std;


double operate (double op1, double op2, char op){
    if(op == '+'){
        return op1 + op2;
    }
    else if(op == '-'){
        return op1 - op2;
    }
    else if(op == '*'){
        return op1 * op2;
    }
    else if(op == '/'){
        return op1 / op2;
    }
}

int main(){
    string input;
    stack<double> st;
    int N;

    cin >> N;
    cin >> input;

    int array[N];
    char current_char;

    // 각 변수는 변수 - 'A' 에 저장됨.
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }

    for(int i = 0; i < input.length(); i++){
        current_char = input[i];
        //현재 문자가 A~Z면 해당 값을 push
        if(current_char >= 'A' && current_char <= 'Z'){
            st.push(array[current_char - 'A']);
        }
        //연산자가 오면 stack의 맨 위 2개와 연산한 후 결과값을 push
        else if(current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/'){
            double op2 = st.top();
            st.pop();
            double op1 = st.top();
            st.pop();
            st.push(operate(op1, op2, current_char));
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}