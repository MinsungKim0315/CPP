#include <iostream>
using namespace std;
#define SUM(a,b) ((a)+(b))
#define SQ(x) ((x)*(x))
#define MUL(a,b) ((a)*(b))
inline int square(int x) {//컴파일러에 의해 처리되는 inline함수를 이용
	return x * x;
}
int main() {
	cout << "(3+4)*5=" << SUM(3, 4) * 5 << endl;
	cout << "(1+2)*(3+4)=" << MUL(1 + 2, 3 + 4) << endl;
	int n = 3;
	cout << "macro : " << SQ(++n) << endl;
	//매크로 함수 SQ(++n) = ( (++n) * (++n) ) , 매크로 함수의 사용은 권장하지 않는다
	n = 3;
	cout << "inline : " << square(++n) << endl;// square(++x) > x=++n; x*x;
	return 0;
}// 매크로 함수의 문제점을 해결하면서 실행 성능을 향상.
