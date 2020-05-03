#include<iostream>
using namespace std;

int N, M, H;
int ladder[31][10];

bool check_start_end_equal(){
    for(int start = 1; start <= N; start++){
        int current = start;
        for(int height = 1; height <= H; height++){
            //현재 1번일 경우 2번과 잇는 가로선이 있다면 2로 이동
            if(current == 1 && ladder[height][current] == 1){
                current++;
            }
            //현재 N번일 경우 N-1번과 잇는 가로선이 있다면 N-1로 이동
            else if(current == N && ladder[height][current-1] == 1){
                current--;
            }
            //그 외에는 양쪽 모두 확인하고 가로선이 있는 곳으로 이동
            else {
                if(ladder[height][current] == 1){
                    current++;
                }
                else if(ladder[height][current-1] == 1){
                    current--;
                }
            }
        }
        // 시작과 끝이 다르다면 false 반환
        if(current != start){
            return false;
        }
    }
    return true;
}

bool can_we_put_line(int a, int b){
    // 둘 중 하나라도 0이면 안 쓰는 칸이므로 넘김
    if((a * b) == 0 ){
        return false;
    }
    // 해당 위치에 가로선이 있으면 넘김
    if(ladder[a][b] == 1){
        return false;
    }
    int left_b = b - 1;
    int right_b = b + 1;
    // 왼쪽에 가로선이 있으면 넘김
    if(left_b >= 1 && ladder[a][left_b] == 1){
        return false;;
    }
    // 오른쪽에 가로선이 있으면 넘김
    if(right_b <= N-1 && ladder[a][right_b] == 1){
        return false;;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    // 아무런 사다리를 추가로 놓지 않았을 때 확인
    if(check_start_end_equal() == true){
        cout << 0;
        return 0;
    }
    // ladder 를 1차원 배열로 생각
    int ladder_size = N * (H+1);
    // 가로선을 1개만 둘 때
    for (int first_line = 0; first_line < ladder_size; first_line++){
        // 2차원 배열 위치로 변환
        int first_line_a = first_line / N;
        int first_line_b = first_line % N;
        // 해당 칸에 가로선을 그을 수 있는 지 확인
        if(can_we_put_line(first_line_a, first_line_b) == false){
            continue;
        }
        ladder[first_line_a][first_line_b] = 1;
        if(check_start_end_equal()){
            cout << 1;
            return 0;
        }
        ladder[first_line_a][first_line_b] = 0;
    }
    // 가로선을 2개만 둘 때
    for (int first_line = 0; first_line < ladder_size - 1; first_line++){
        // 2차원 배열 위치로 변환
        int first_line_a = first_line / N;
        int first_line_b = first_line % N;
        // 해당 칸에 가로선을 그을 수 있는 지 확인
        if(can_we_put_line(first_line_a, first_line_b) == false){
            continue;
        }
        ladder[first_line_a][first_line_b] = 1;
        // 가로선을 1개만 둘 때
        for (int second_line = first_line+1; second_line < ladder_size; second_line++){
            // 2차원 배열 위치로 변환
            int second_line_a = second_line / N;
            int second_line_b = second_line % N;
            // 해당 칸에 가로선을 그을 수 있는 지 확인
            if(can_we_put_line(second_line_a, second_line_b) == false){
                continue;
            }
            ladder[second_line_a][second_line_b] = 1;
            if(check_start_end_equal()){
                cout << 2;
                return 0;
            }
            ladder[second_line_a][second_line_b] = 0;
        }
        ladder[first_line_a][first_line_b] = 0;
    }
    // 가로선을 3개만 둘 때
    for (int first_line = 0; first_line < ladder_size - 2; first_line++){
        // 2차원 배열 위치로 변환
        int first_line_a = first_line / N;
        int first_line_b = first_line % N;
        // 해당 칸에 가로선을 그을 수 있는 지 확인
        if(can_we_put_line(first_line_a, first_line_b) == false){
            continue;
        }
        ladder[first_line_a][first_line_b] = 1;
        // 가로선을 1개만 둘 때
        for (int second_line = first_line+1; second_line < ladder_size - 1; second_line++){
            // 2차원 배열 위치로 변환
            int second_line_a = second_line / N;
            int second_line_b = second_line % N;
            // 해당 칸에 가로선을 그을 수 있는 지 확인
            if(can_we_put_line(second_line_a, second_line_b) == false){
                continue;
            }
            ladder[second_line_a][second_line_b] = 1;
            for (int third_line = second_line+1; third_line < ladder_size; third_line++){
                // 2차원 배열 위치로 변환
                int third_line_a = third_line / N;
                int third_line_b = third_line % N;
                // 해당 칸에 가로선을 그을 수 있는 지 확인
                if(can_we_put_line(third_line_a, third_line_b) == false){
                    continue;
                }
                ladder[third_line_a][third_line_b] = 1;
                if(check_start_end_equal()){
                    cout << 3;
                    return 0;
                }
                ladder[third_line_a][third_line_b] = 0;
            }
            ladder[second_line_a][second_line_b] = 0;
        }
        ladder[first_line_a][first_line_b] = 0;
    }
    cout << -1;
    return 0;
}