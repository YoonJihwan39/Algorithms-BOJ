#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int length[9];
    int real[7];
    int sum = 0;
    int count = 0;
    int fake1 = -1, fake2 = -1;

    for(int i = 0; i < 9; i++){
        cin >> length[i];
        sum += length[i];
    }

    for(int i = 0; i < 9; i++){
        if(sum - length[i] <= 100){
            continue;
        }
        for(int j = i+1; j < 9; j++){
            if(sum - length[i] - length[j] == 100){
                fake1 = i;
                fake2 = j;
                break;
            }
        }
        if(fake1 != -1 || fake2 != -1){
            break;
        }
    }
    for(int i = 0; i < 9; i++){
        if(i == fake1 || i == fake2){
            continue;
        }
        real[count] = length[i];
        count++;
    }

    sort(real, real+7);

    for(int i = 0; i < 7; i++){
        cout << real[i] << '\n';
    }
}