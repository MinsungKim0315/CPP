#include <iostream>
#include <iomanip>
//left, right, setw(), fixed, unsetf(ios::fixed)
//setfill(), setbase(), setprecision()
using namespace std;
int main() {
  //cout << setfill('0');
  //cout << setbase(10); // 정수형 적용 가능
  cout << setprecision(4);  //setprecision(n): n 자릿수 만큼 반올림
  for (int i = 1; i <= 100; i++) {
    if (i % 2 == 0) {
      cout << fixed;  //fixed: 소수분만을 기준으로 반올림
      cout << right;
      cout << setw(10) << i / 3.0;  //setw(n): 출력시 길이를 n으로 지정
      cout << endl;
    }
    else {
      cout << defaultfloat; // fixed 서식 해제
      cout << left;
      cout << setw(10) << i / 3.0 << "│";
    }
  }
  cout << endl;
  return 0;
}
