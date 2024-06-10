#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���� ��å
void find_start(vector<string> park, int& x, int& y) {
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == 'S') {
                x = i;
                y = j;
                return;
            }
        }
    }
}

vector<int> solution7(vector<string> park, vector<string> routes) {
    vector<int> answer(2);
    int y = park.size();    //�ִ� �� ��
    int x = park[0].size(); //�ִ� ĭ ��
    find_start(park, answer[0], answer[1]);
    for (auto& cmd : routes) {
        char dir = cmd[0];          //����
        int move = cmd[2] - '0';    //�̵� ĭ ��
        for (int ck = 1; ck <= move; ck++) {
            if (dir == 'E' && (answer[1] + ck) < x && park[answer[0]][answer[1] + ck] != 'X') { //������ ����� �ȉ� && Xģ ĭ�� ����
                if (ck == move)answer[1] += ck;
            }
            else if (dir == 'W' && (answer[1] - ck) >= 0 && park[answer[0]][answer[1] - ck] != 'X') {
                if (ck == move)answer[1] -= ck;
            }
            else if (dir == 'S' && (answer[0] + ck < y) && park[answer[0] + ck][answer[1]] != 'X') {
                if (ck == move)answer[0] += ck;
            }
            else if (dir == 'N' && (answer[0] - ck << y >= 0) && park[answer[0] - ck][answer[1]] != 'X') {
                if (ck == move)answer[0] -= ck;
            }
            else break;
        }
    }
    return answer;
}

int main() {
    for (auto& p : solution7({ "SOO","OOO","OOO" }, { "E 2","S 2","W 1" })) cout << p << " "; cout << endl;  // 2 1
    for (auto& p : solution7({ "SOO","OXX","OOO" }, { "E 2","S 2","W 1" })) cout << p << " "; cout << endl;  // 0 1
    for (auto& p : solution7({ "OSO","OOO","OXO","OOO" }, { "E 2","S 2","W 1" })) cout << p << " "; cout << endl;  // 0 0
}
