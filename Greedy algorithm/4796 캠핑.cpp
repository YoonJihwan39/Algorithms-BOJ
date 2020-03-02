#include<iostream>
using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, P, V;
    int L_copy, P_copy;
    int result;
    int test_case = 0;

    while(1){

        test_case++;
        result = 0;

        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;
        
        L_copy = L;
        P_copy = P;

        while(V > 0){
            //먼저 사용
            if(V >= L){
                V -= L;
                result += L;
            }
            else {
                result += V;
                V = 0;
                break;
            }

            //사용할 수 없는 날짜
            if(V >= P - L){
                V -= P - L;
            }
            else {
                break;
            }
        }
        cout << "Case " << test_case << ": " << result << '\n';
    }
    return 0;
}