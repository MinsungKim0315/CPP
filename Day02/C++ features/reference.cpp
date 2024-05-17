#include <iostream>
#include <cstdlib>
using namespace std;
void swap(char& x, char& y) { char temp = x; x = y;  y = temp; }
void swap(int& x, int& y) { int temp = x; x = y; y = temp; }
void swap(double& x, double& y) { double temp = x; x = y; y = temp; }
void swap(char* p1, char* p2) {
  char* temp = (char*)malloc((strlen(p1) > strlen(p2)) ? strlen(p1) + 1 : strlen(p2) + 1); // 동적 할당 
  for (int i = 0; i <= strlen(p1); i++) temp[i] = p1[i];
  for (int i = 0; i <= strlen(p2); i++) p1[i] = p2[i];
  for (int i = 0; i <= strlen(temp); i++) p2[i] = temp[i];
  free(temp);
}
void swap(char(&p1)[255], char(&p2)[255]) {
  char temp[255];
  for (int i = 0; i <= strlen(p1); i++) temp[i] = p1[i];
  for (int i = 0; i <= strlen(p2); i++) p1[i] = p2[i];
  for (int i = 0; i <= strlen(temp); i++) p2[i] = temp[i];
}
int main() {
  char c1, c2;
  cout << "문자 2개 입력 (공백 구분) : ";
  cin >> c1 >> c2;
  cout << "교환 전 : " << c1 << ", " << c2 << endl;
  swap(c1, c2);
  cout << "교환 후 : " << c1 << ", " << c2 << endl << endl;
  int i1, i2;
  cout << "정수 2개 입력 (공백 구분) : ";
  cin >> i1 >> i2;
  cout << "교환 전 : " << i1 << ", " << i2 << endl;
  swap(i1, i2);
  cout << "교환 후 : " << i1 << ", " << i2 << endl << endl;
  double d1, d2;
  cout << "실수 2개 입력 (공백 구분) : ";
  cin >> d1 >> d2;
  cout << "교환 전 : " << d1 << ", " << d2 << endl;
  swap(d1, d2);
  cout << "교환 후 : " << d1 << ", " << d2 << endl << endl;
  char str1[55], str2[55];
  cout << "문자열 2개 입력 (공백 구분) : ";
  cin >> str1 >> str2;
  cout << "교환 전 : " << str1 << ", " << str2 << endl;
  swap(str1, str2);
  cout << "교환 후 : " << str1 << ", " << str2 << endl << endl;
  return 0;
}
