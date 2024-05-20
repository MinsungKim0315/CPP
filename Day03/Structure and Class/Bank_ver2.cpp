//구조체 멤버 변수 + 멤버 함수 ver.
#include <iostream>
using namespace std;
struct ACT {
    int ACTId;              //계좌번호
    char pw[5];             //비밀번호
    char name[20];          //이름
    int bal;                //잔액
    void showData() {
        cout << "\n계좌번호 : " << ACTId << endl;
        cout << name << " 회원님의 잔액은 " << bal << "입니다.\n";
    }
    void deposit() {
        int m;
        cout << "\n입금금액 입력 : ";
        cin >> m;        bal += m;
        cout << "\t\t" << m << "원 입금완료.\n";
    }
    void withdraw() {
        int m;
        cout << "\n출금금액 입력 : ";
        cin >> m;        bal -= m;
        cout << "\t\t" << m << "원 출금완료.\n";
    }
};
int main(){
    ACT act_1 = { 1234, "5678", "chris", 10000 };
    act_1.showData(); //계좌 정보 출력 멤버 함수 호출
    act_1.deposit(); //입금 멤버 함수 호출
    act_1.withdraw(); //출금 멤버 함수 호출
    act_1.showData(); //계좌 정보 출력 멤버 함수 호출
}
