//구조체 멤버 변수 ver.
#include <iostream>
using namespace std;
struct ACT {
    int ACTId;              //계좌번호
    char pw[5];             //비밀번호
    char name[20];          //이름
    int bal;                //잔액
};
void showData(ACT& a) {
    cout << "\n계좌번호: " << a.ACTId << endl;
    cout << a.name << " 회원님의 잔액은 " << a.bal << endl;
}
void deposit(ACT& a) {
    int m;
    cout << "\n입금금액: ";
    cin >> m;
    a.bal += m;
    cout << "\t\t" << m << "원 입금완료\n";
}
void withdrawl(ACT& a) {
    int m;
    cout << "\n출금금액: ";
    cin >> m;
    a.bal -= m;
    cout << "\t\t" << m << "원 출금완료\n";
}
int main() {
    ACT act_1 = { 1234, "5679", "chris", 10000 };
    showData(act_1);
    deposit(act_1);
    withdrawl(act_1);
    showData(act_1);
}
