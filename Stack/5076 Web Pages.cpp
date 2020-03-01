#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string input;
    string tag;
    stack<string> tag_stack;
    bool result;
    while(1){
        result = true;
        getline(cin, input);

        //빈 문자열이면 legal을 출력하고 다음 문장으로(런타임 에러 방지)
        if(input.empty()){
            cout << "legal\n";
            continue;
        }

        //#이면 반복문을 나가고 종료
        if(input[0] == '#'){
            break;
        }

        for(int i = 0; i < input.length(); i++){
            //현재 문자가 <인 경우 tag에 저장
            if(input[i] == '<'){
                tag = "";
                i++;
                //공백이나 '>'가 올때까지 tag에 저장
                while(i < input.length() && input[i] != ' ' && input[i] != '>'){
                    tag += input[i];
                    i++;
                }
                // 태그 뒤에 " /" 가 있으면 아무것도 하지 않고 다음 문자로
                if(i+1 < input.length() && input[i] == ' ' && input[i+1] == '/'){
                    continue;
                }
                //tag가 비어 있거나(런타임 에러 방지) '/'로 시작하지 않으면 push
                else if(tag.empty() || tag[0] != '/'){
                    tag_stack.push(tag);
                }
                // 태그가 '/'로 시작한다면
                else {
                    tag = tag.substr(1);
                    //태그가 stack의 맨 위와 다르거나 stack이 비어 있으면 illegal
                    if(tag_stack.empty() || tag != tag_stack.top()){
                        result = false;
                        break;
                    }
                    //태그가 stack의 맨 위와 같으면 pop
                    else {
                        tag_stack.pop();
                    }
                }
            }
        }
        if(!tag_stack.empty()) {
            result = false;
        }

        if(result){
            cout << "legal\n";
        }
        else {
            cout << "illegal\n";
        }

        while(!tag_stack.empty()) tag_stack.pop();
        
    }
    return 0;
}