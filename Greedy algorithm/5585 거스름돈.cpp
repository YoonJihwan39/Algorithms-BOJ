#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int pay;
    int count = 0;
    cin >> pay;
    int change = 1000 - pay;
    int unit[6] = {500, 100, 50, 10, 5, 1};
    for(int i = 0; i < 6; i++){
        while(change >= unit[i]){
            change -= unit[i];
            count++;
        }
        if(change == 0){
            break;
        }
    }
    cout << count;
    return 0;

}