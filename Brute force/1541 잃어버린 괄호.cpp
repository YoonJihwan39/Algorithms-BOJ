#include<iostream>
#include<vector>
using namespace std;

string input;
int main(){
    int result = 0;
    vector<int> digit;
    vector<char> op;
    cin >> input;
    //먼저 식을 숫자와 연산자로 나눔.
    for(int i = 0; i < input.length(); i++){
        string temp = "";
        if(input[i] >= '0' && input[i] <= '9'){
            temp += input[i];
            i++;
            while(i < input.length()){
                if(input[i] >= '0' && input[i] <= '9'){
                    temp += input[i];
                    i++;
                }
                else{
                    i--;
                    break;
                }
            }
            digit.push_back(stoi(temp));
        }
        else{
            op.push_back(input[i]);
        }
    }
    result += digit[0];
    for(int i = 0; i < op.size(); i++){
        if(op[i] == '+'){
            result += digit[i+1];
        }
        // -라면 다른 -가 나오기 전까지 계속 더해주면 됨.
        else{
            int temp = digit[i+1];
            i++;
            while(i < op.size()){
                if(op[i] == '+'){
                    temp += digit[i+1];
                    i++;
                }
                else{
                    i--;
                    break;
                }
            }
            result -= temp;
        }
    }
    cout << result;
    return 0;
}