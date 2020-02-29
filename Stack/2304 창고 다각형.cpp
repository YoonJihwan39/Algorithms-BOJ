#include<iostream>
#include<stack>
using namespace std;

int main() {
    int N;
    int location;
    int top_location, top_height = 0;
    int array[1001] = {0, };
    int area = 0;
    int current_height;
    stack<int> top_stack;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> location;
        cin >> array[location];
        if(array[location] >= top_height){
            top_location = location;
            top_height = array[location];
        }
    }
    //가장 높은 기둥까지의 넓이 구하기
    for(int i = 1; i < top_location; i++){
        current_height = array[i];
        if(top_stack.empty() || current_height > top_stack.top()){
            top_stack.push(current_height);
        }
        area += top_stack.top();
    }

    //가장 높은 기둥의 넓이
    area += top_height;
    
    while(!top_stack.empty()) top_stack.pop();

    //끝에서 가장 높은 기둥까지의 넓이
    for(int i = 1000; i > top_location; i--){
        current_height = array[i];
        if(top_stack.empty() || current_height > top_stack.top()){
            top_stack.push(current_height);
        }
        area += top_stack.top();
    }
    cout << area;
    return 0;
}