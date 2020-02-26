#include<iostream>
#include<stack>
using namespace std;

int main(){
    int N;
    stack<int> top;
    cin >> N;
    int histogram[N+1];
    int result = 0;

    histogram[N] = 0;

    for(int i = 0; i < N; i++){
        cin >> histogram[i];
    }

    for(int i = 0; i <= N; i++){
        while(!top.empty() && histogram[top.top()] > histogram[i]){ //현재보다 낮은 높이가 나올 때까지 pop.
            int height = histogram[top.top()];
            int width;
            top.pop();
            if(top.empty()){ //top이 비어있다면 처음부터 top까지 top보다 낮은게 없으므로 길이를 처음부터 i까지
                width = i;
            }
            else { //비어있지 않다면 다음 top까지의 거리를 밑변으로함.
                width = i - top.top() - 1;
            }
            int area = height * width;
            if(area > result){
                result = area;
            }
        }
        top.push(i);
    }
    cout << result;
    return 0;
}