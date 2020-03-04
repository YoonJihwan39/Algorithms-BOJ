#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
using namespace std;

vector<pair<int, int>> cube;
bool impossible;
int N;
int result = 0;

bool desc(pair<int, int> a, pair<int, int> b){
    return a > b;
}

void filling (int l, int w, int h){
    if(impossible == true){
        return;
    }
    int array[3] = {l, w, h};

    //길이를 오름차순 정렬
    sort(array, array+3);
    int p = 0;
    //제일 짧은 변의 길이보다 작으면서 제일 큰 2^p를 찾아냄
    while(pow(2, p) <= array[0]){
        p++;
    }
    p--;

    //2^p보다 작으면서 제일 큰 큐브를 찾아냄
    int i;
    for(i = 0; i < N; i++){
        if(pow(2, p) >= cube[i].first && cube[i].second != 0){
            break;
        }
        if(i == N - 1){
            impossible = 1;
            return;
        }
    }

    //가장 긴 길이에서 큐브의 개수만큼 채움.
    int temp = min(array[2]/cube[i].first, cube[i].second);
    result += temp;
    cube[i].second -= temp;
    
    //각 변에서 큐브를 뺀 것 만큼 재귀 
    if(array[2] - temp * cube[i].first != 0){
        filling(cube[i].first, cube[i].first, array[2] - temp * cube[i].first);
    }
    if(array[0] - cube[i].first != 0){
        filling(array[0] - cube[i].first, cube[i].first, array[2]);
    }
    if(array[1] - cube[i].first != 0){
        filling(array[0], array[1] - cube[i].first, array[2]);
    }

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int length, width, height;

    cin >> length >> width >> height;

    cin >> N;
    int size, num;
    for(int i = 0; i < N; i++){
        cin >> size >> num;
        //vector에 큐브 한변의 길이와 개수 저장.
        cube.push_back(make_pair(pow(2, size), num));
    }

    //크기 내림차순 정렬
    sort(cube.begin(), cube.end(), desc);

    filling(length, width, height);

    if(impossible) {
        cout << -1;
    }
    else {
        cout << result;
    }
    return 0;
}