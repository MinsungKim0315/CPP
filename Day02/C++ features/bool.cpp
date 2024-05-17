#include <iostream>
using namespace std;
bool isEvenNumber(int number) {
  if (number % 2 == 0) return true; // == 1;
  else return false; // == 0;
}
int main() {
  //bool : true, false의 값을 갖는 1바이트 자료형(true는 1로, false는 0으로 처리된다.)
  int num;
  bool True = -10.125; // 0이 아니면 true
  bool False = 0; // false
  cout << "bool 자료형 크기 : " << sizeof(bool) << " byte" << endl;
  cout << "True: " << True << " False : " << False << endl << endl;
  cout << "정수 입력 : ";
  cin >> num;
  if (isEvenNumber(num)) cout << "짝수 입니다." << endl;
  else cout << "홀수 입니다." << endl;
}
