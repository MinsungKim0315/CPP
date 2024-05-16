#include <iostream>
using namespace std;
//square함수 오버로딩
int square(int a) {
	return a * a;
}
double square(double a) {
	return a * a;
}
// Date함수 오버로딩
void date(int year, int month, int day) {
	cout << year << "년/" << month << "월/" << day << "일" << endl;
}
void date(int year, int month, int day, const char* separate) {
	cout << year << "년" << separate << month << "월" << separate << day << "일" << endl;
}
//getTotal함수 오버로딩
int getTotal() {
	int sum = 0;
	for (int i = 1; i <= 100; i++) sum += i;
	return sum;
}
int getTotal(int x) {
	int sum = 0;
	for (int i = x; i <= 100; i++) sum += i;
	return sum;
}
int getTotal(int x, int y) {
	int sum = 0;
	for (int i = x; i <= y; i++) sum += i;
	return sum;
}
int main() {
	int su;
	cout << "정수 입력 : ";
	cin >> su;
	cout << "정수 제곱값 : " << square(su) << endl;
	double f;
	cout << "실수 입력 : ";
	cin >> f;
	cout << "실수 제곱값 : " << square(f) << endl;

	date(2022, 01, 01);
	date(2022, 01, 01, "★");

	cout << getTotal() << endl;
	cout << getTotal(50) << endl;
	cout << getTotal(50, 500) << endl;
	return 0;
}
