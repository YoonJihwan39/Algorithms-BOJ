#include<iostream>
#include<vector>
using namespace std;

int G;
vector<int> ans;

int main(){
    cin >> G;

    //c가 50001이상이 되면 c^2 - r^2이 100000을 넘어감
    long long c = 1, r = 1;
    long long result = 0; 
    while(1){
        //G보다 크면 r을 증가
        if(result > G){
            result += r*r;
            r++;
            result -= r*r;
        }
        else if(c == 50001){
            break;
        }
        else {
            result -= c*c;
            c++;
            result += c*c;
        }

        if(result == G){
            ans.push_back(c);
        }
    }

    if(ans.empty()){
        cout << -1;
    }
    else {
        for(auto &p: ans){
            cout << p << '\n';
        }
    }
    return 0;
}