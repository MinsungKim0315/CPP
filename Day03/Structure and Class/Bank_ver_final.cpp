//class 멤버 변수 + 멤버 함수 선언ver. + 접근제어지시자
#include <iostream>
using namespace std;
class ACT {
private: //선언된 클래스 내에서만 접근허용
  int ACTId;              //계좌번호
  char pw[5];             //비밀번호
  char name[20];          //이름
  int bal;                //잔액
public: //어디서든 접근허용
  void Init_act(int _actid, char* _PW, char* _NAME, int _BAL);
  void showData(); //계좌정보 출력
  void deposit(); //입금 함수 & 출력
  void withdraw();//출금 함수 & 출력
};
int main() {
  ACT act_1;
  act_1.Init_act(1234, (char*)"5678", (char*)"chris", 10000);
  act_1.showData(); //계좌 정보 출력 함수 호출
  act_1.deposit(); //입금 멤버 함수 호출
  act_1.withdraw(); //출금 멤버 함수 호출
  act_1.showData(); //계좌 정보 출력 함수 호출
}
void ACT::Init_act(int _actid, char* _PW, char* _NAME, int _BAL) {
  ACTId = _actid;
  strcpy_s(pw, strlen(_PW) + 1, _PW);
  strcpy_s(name, strlen(_NAME) + 1, _NAME);
  bal = _BAL;}
void ACT::showData() {
  cout << "\n계좌번호 : " << ACTId << endl;
  cout << name << " 회원님의 잔액은 " << bal << "입니다.\n";}
void ACT::deposit() {
  int m;
  cout << "\n입금금액 입력 : ";
  cin >> m;  bal += m;
  cout << "\t\t" << m << "원 입금완료.\n";}
void ACT::withdraw() {
  int m;
  cout << "\n출금금액 입력 : ";
  cin >> m;  bal -= m;
  cout << "\t\t" << m << "원 출금완료.\n";}
