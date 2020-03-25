#include<iostream>
using namespace std;

int N, M, P;
int channel[100001]; //각 채널마다 싫어하는 가장 어린 사람이 좋아하는 채널을 저장
bool visited[100001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> P;
    visited[P] = 1;
    int favorite_channel, hate_channel;
    for(int i = 0; i < N; i++){
        cin >> favorite_channel >> hate_channel;
        if(channel[hate_channel] == 0){
            channel[hate_channel] = favorite_channel;
        }
    }
    int result = 0;
    // 해당 채널을 싫어하는 사람이 없을 때까지 반복
    while(channel[P] != 0){
        //만약 해당 채널을 이미 봤었다면 무한 loop이므로 break
        if(visited[channel[P]] == 1){
            result = -1;
            break;
        }
        result++;
        P = channel[P];
        visited[P] = 1;
    }
    cout << result;
    return 0;
}