#include <iostream>
#include <vector>
using namespace std;

int T;
int n;

char cube[6][3][3];
vector<string> rotate;
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

void rotate_cube(){
    for(int i = 0; i < rotate.size(); i++){
        char face = rotate[i][0];
        int face_num;
        char dir = rotate[i][1];
        if(face == 'U' && dir == '+'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[5][0][i], cube[2][0][i], cube[4][0][i], cube[3][0][i]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[2][0][i] = cache[i][0];
                cube[4][0][i] = cache[i][1];
                cube[3][0][i] = cache[i][2];
                cube[5][0][i] = cache[i][3];
                face_num = 0;
            }
        }
        else if(face == 'U' && dir == '-'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[4][0][i], cube[5][0][i], cube[3][0][i], cube[2][0][i]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[2][0][i] = cache[i][0];
                cube[3][0][i] = cache[i][1];
                cube[4][0][i] = cache[i][2];
                cube[5][0][i] = cache[i][3];
                face_num = 0;
            }
        }
        else if(face == 'D' && dir == '+'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[4][2][i], cube[2][2][i], cube[5][2][i], cube[3][2][i]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[2][2][i] = cache[i][0];
                cube[5][2][i] = cache[i][1];
                cube[3][2][i] = cache[i][2];
                cube[4][2][i] = cache[i][3];
                face_num = 1;
            }
        }
        else if(face == 'D' && dir == '-'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[5][2][i], cube[3][2][i], cube[4][2][i], cube[2][2][i]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[2][2][i] = cache[i][0];
                cube[5][2][i] = cache[i][1];
                cube[3][2][i] = cache[i][2];
                cube[4][2][i] = cache[i][3];
                face_num = 1;
            }
        }
        else if(face == 'F' && dir == '+'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[4][(i-2)*-1][2], cube[0][2][i], cube[5][(i-2)*-1][0], cube[1][0][i]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][2][i] = cache[i][0];
                cube[5][i][0] = cache[i][1];
                cube[1][0][i] = cache[i][2];
                cube[4][i][2] = cache[i][3];
                face_num = 2;
            }
        }
        else if(face == 'F' && dir == '-'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[5][i][0], cube[1][0][(i-2)*-1], cube[4][i][2], cube[0][2][(i-2)*-1]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][2][i] = cache[i][0];
                cube[5][i][0] = cache[i][1];
                cube[1][0][i] = cache[i][2];
                cube[4][i][2] = cache[i][3];
                face_num = 2;
            }
        }
        else if(face == 'B' && dir == '+'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[5][i][2], cube[0][0][(i-2)*-1], cube[4][i][0], cube[1][2][(i-2)*-1]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][0][i] = cache[i][0];
                cube[4][i][0] = cache[i][1];
                cube[1][2][i] = cache[i][2];
                cube[5][i][2] = cache[i][3];
                face_num = 3;
            }
        }
        else if(face == 'B' && dir == '-'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[4][(i-2)*-1][0], cube[0][0][i], cube[5][(i-2)*-1][2], cube[1][2][i]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][0][i] = cache[i][0];
                cube[5][i][2] = cache[i][1];
                cube[1][2][i] = cache[i][2];
                cube[4][i][0] = cache[i][3];
                face_num = 3;
            }
        }
        else if(face == 'L' && dir == '+'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[3][(i-2)*-1][2], cube[0][i][0], cube[2][i][0], cube[1][(i-2)*-1][0]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][i][0] = cache[i][0];
                cube[2][i][0] = cache[i][1];
                cube[1][i][0] = cache[i][2];
                cube[3][i][2] = cache[i][3];
                face_num = 4;
            }
        }
        else if(face == 'L' && dir == '-'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[2][i][0], cube[0][(i-2)*-1][0], cube[3][(i-2)*-1][2], cube[1][i][0]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][i][0] = cache[i][0];
                cube[3][i][2] = cache[i][1];
                cube[1][i][0] = cache[i][2];
                cube[2][i][0] = cache[i][3];
                face_num = 4;
            }
        }
        else if(face == 'R' && dir == '+'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[2][i][2], cube[0][(i-2)*-1][2], cube[3][(i-2)*-1][0], cube[1][i][2]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][i][2] = cache[i][0];
                cube[3][i][0] = cache[i][1];
                cube[1][i][2] = cache[i][2];
                cube[2][i][2] = cache[i][3];
                face_num = 5;
            }
        }
        else if(face == 'R' && dir == '-'){
            vector<vector<char>> cache;
            for(int i = 0; i < 3; i++){
                vector<char> temp {cube[3][(i-2)*-1][0], cube[0][i][2], cube[2][i][2], cube[1][(i-2)*-1][2]};
                cache.push_back(temp);
            }
            for(int i = 0; i < 3; i++){
                cube[0][i][2] = cache[i][0];
                cube[2][i][2] = cache[i][1];
                cube[1][i][2] = cache[i][2];
                cube[3][i][0] = cache[i][3];
                face_num = 5;
            }
        }
        if(dir == '+'){
            char temp[8] = {cube[face_num][0][0], cube[face_num][0][1], cube[face_num][0][2], cube[face_num][1][2], 
                            cube[face_num][2][2], cube[face_num][2][1], cube[face_num][2][0], cube[face_num][1][0]};
            cube[face_num][0][0] = temp[6];
            cube[face_num][0][1] = temp[7];
            cube[face_num][0][2] = temp[0];
            cube[face_num][1][2] = temp[1];
            cube[face_num][2][2] = temp[2];
            cube[face_num][2][1] = temp[3];
            cube[face_num][2][0] = temp[4];
            cube[face_num][1][0] = temp[5];
        }
        else if(dir == '-'){
            char temp[8] = {cube[face_num][0][0], cube[face_num][0][1], cube[face_num][0][2], cube[face_num][1][2], 
                            cube[face_num][2][2], cube[face_num][2][1], cube[face_num][2][0], cube[face_num][1][0]};
            cube[face_num][0][0] = temp[2];
            cube[face_num][0][1] = temp[3];
            cube[face_num][0][2] = temp[4];
            cube[face_num][1][2] = temp[5];
            cube[face_num][2][2] = temp[6];
            cube[face_num][2][1] = temp[7];
            cube[face_num][2][0] = temp[0];
            cube[face_num][1][0] = temp[1];
        }
    }
    return;
}

int main(){
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        //초기화
        rotate.clear();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    cube[i][j][k] = color[i];
                }
            }
        }
        cin >> n;
        string input;
        for(int i = 0; i < n; i++){
            cin >> input;
            rotate.push_back(input);
        }
        rotate_cube();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}