#include<iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point operator+ (const Point& r) {	//Point + Point
		Point temp;
		temp.x = this->x + r.x;
		temp.y = this->y + r.y;
		return temp;
	}
	Point operator- (const Point& r) {	//Point - Point
		Point temp;
		temp.x = this->x - r.x;
		temp.y = this->y - r.y;
		return temp;
	}
	Point& operator++() {
		x += 1;
		y += 1;
		return *this;
	}
	Point operator++(int) {
		Point temp;
		temp.x = x;
		temp.y = y;
		x += 1;
		y += 1;
		return temp;
	}
	inline int GetX() { return x; }
	inline int GetY() { return y; }

	//멤버 접근 허용
	friend Point operator+(int value, const Point& r);
	friend Point operator-(int value, const Point& r);
};
Point operator+(int value, const Point& r) {
	return Point(r.x + value, r.y + value);
}
Point operator-(int value, const Point& r) {
	return Point(r.x - value, r.y - value);
}
int main() {
	int x, y;
	cout << "첫 번째 x, y좌표 입력 : ";
	cin >> x >> y;
	Point p1(x, y);
	Point p2 = 10 + p1; //10.operator+(p1) //불가능 -> operator+(10, p1) //전역함수 오버로딩으로 해결
	cout << "p1(" << p1.GetX() << ", " << p1.GetY() << ")\n";
	cout << "p2(" << p2.GetX() << ", " << p2.GetY() << ")\n";
	++++++p1;
	cout << p1.GetX() << ", " << p1.GetY() << "\n";
	p1++;
	cout << p1.GetX() << ", " << p1.GetY() << "\n";
	return 0;
}
