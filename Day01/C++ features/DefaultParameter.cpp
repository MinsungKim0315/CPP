//등비수열의 합을 구하는 함수 
#include <iostream>
#include <cmath>
using namespace std;
double  geometric_sqc_sum(int a = 1, int r = 2, int n = 5);
//  Default parameter 함수의 원형(선언부)만 작성
int main() {
	cout << geometric_sqc_sum() << endl; // 31
	cout << geometric_sqc_sum(5) << endl; // 155
	cout << geometric_sqc_sum(5, 3) << endl; // 605
	cout << geometric_sqc_sum(5, 3, 7) << endl; // 5465
	return 0;
}

double  geometric_sqc_sum(int a, int r, int n) {
	if (r == 1)  return n * a;
	else return (a * ((pow(r, n) - 1))) / (r - 1);
}
