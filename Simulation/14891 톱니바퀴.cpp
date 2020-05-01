#include<iostream>
#include<vector>
using namespace std;

string gear[5];
vector<pair<int, int>> rotate;
int K;
bool rotated[5];

void rotate_gear(int nth, int dir){
    if(dir == 1){
        char temp1 = gear[nth][7], temp2;
        for(int i = 0; i < 8; i++){
            temp2 = gear[nth][i];
            gear[nth][i] = temp1;
            temp1 = temp2;
        }
    }
    else {
        char temp1 = gear[nth][0], temp2;
        for(int i = 7; i >= 0; i--){
            temp2 = gear[nth][i];
            gear[nth][i] = temp1;
            temp1 = temp2;
        }
    }
    return;
}

void check_and_rotate(int nth, int dir){
    rotated[nth] = 1;
    if(nth == 1){
        if(rotated[nth+1] == 0 && gear[nth][2] != gear[nth+1][6]){
            check_and_rotate(nth+1, dir * -1);
        }
    }
    else if(nth == 2 || nth == 3){
        if(rotated[nth-1] == 0 && gear[nth-1][2] != gear[nth][6]){
            check_and_rotate(nth-1, dir * -1);
        }
        if(rotated[nth+1] == 0 && gear[nth][2] != gear[nth+1][6]){
            check_and_rotate(nth+1, dir * -1);
        }
    }
    else if(nth == 4){
        if(rotated[nth-1] == 0 && gear[nth-1][2] != gear[nth][6]){
            check_and_rotate(nth-1, dir * -1);
        }
    }
    rotate_gear(nth, dir);
    return;
}

int main(){
    for(int i = 1; i <= 4; i++){
        cin >> gear[i];
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        int nth, dir;
        cin >> nth >> dir;
        rotate.push_back(make_pair(nth, dir));
    }


    for(int i = 0; i < rotate.size(); i++){
        for(int j = 0; j < 5; j++){
            rotated[j] = 0;
        }
        check_and_rotate(rotate[i].first, rotate[i].second);
    }
    cout << (gear[1][0] - '0') + 2 * (gear[2][0] - '0') + 4 * (gear[3][0] - '0') + 8 * (gear[4][0] - '0');
    return 0;
}
