#include<iostream>
#include<map>
using namespace std;

long long N;
int P, Q;
map<long long, long long> m;

long long dp(long long n){
    map<long long, long long>::iterator iter = m.find(n);
    if(iter != m.end()){
        return m[n];
    }
    long long result = dp(n / P) + dp(n / Q);
    m.insert(make_pair(n, result));
    return result;
}

int main(){
    m.insert(make_pair(0, 1));
    cin >> N >> P >> Q;
    cout << dp(N);
    return 0;
}