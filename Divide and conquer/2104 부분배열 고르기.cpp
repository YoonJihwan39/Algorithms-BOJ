// 참조: https://lyzqm.blogspot.com/2017/11/2104-12846.html
#include<iostream>
using namespace std;

int array[100000];
int N;

long long select_max(int begin, int end){
    long long result;
    if(begin == end){
        return (long long) array[begin] * array[begin];
    }
    int mid = (begin + end) / 2;

    //mid 기준 왼쪽과 오른쪽 중 큰 것을 결과로 지정.
    result = max(select_max(begin, mid), select_max(mid+1, end));

    //mid와 mid + 1 계산
    int left = mid, right = mid + 1;
    long long minimum = min(array[left], array[right]);
    long long sum = array[left] + array[right];
    result = max(result, sum * minimum);

    //좌우로 확장
    while(begin < left || right < end){
        //오른쪽과 왼쪽에 공간이 있다면 둘 중 큰 곳을 먼저 확장, 공간이 없다면 있는 곳 우선.
        //오른쪽 확장
        if(left == begin || (right < end && array[left - 1] < array[right + 1])){
            right++;
            minimum = min(minimum, (long long)array[right]);
            sum = sum + array[right];
        } 
        else {
            left--;
            minimum = min(minimum, (long long) array[left]);
            sum = sum + array[left];
        }
        result = max(result, sum * minimum);
    }
    return result;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> array[i];
    }
    cout << select_max(0, N-1);
    return 0;

}