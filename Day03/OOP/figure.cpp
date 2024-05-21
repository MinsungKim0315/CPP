#include <iostream>
#include <cmath>
using namespace std;

class figure {
public:
  float width, height; //폭(가로), 높이(세로)
  char* shape;// 출력 모양
  // 매개변수로 멤버 변수 초기화
  void Setfigure(float _width, float _height, char* _shape);
  void print_rectangular(); // 사각형 그리기
  void print_right_triangle(); // 오른쪽 직각 삼각형 그리기
  void print_left_triangle(); // 왼쪽 직각 삼각형 그리기
  void print_isosceles_triangle(); // 이등변 삼각형 그리기
};
void figure::Setfigure(float _width, float _height, char* _shape) {
  width = _width;
  height = _height;
  shape = _shape;
}
void figure::print_rectangular() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << shape;
    }
    cout << endl;
  }
}
void figure::print_right_triangle() {
  for (int i = 0; i <= height; i++) {
    for (int j = 0; j < (width - ceil(i / (height / width))); j++) cout << "  ";
    for (int j = 0; j < (i / (height / width)); j++) cout << shape;
    cout << endl;
  }
}
void figure::print_left_triangle() {
  for (int i = 0; i <= height; i++) {
    for (int j = 0; j < (i / (height / width)); j++) {
      cout << shape;
    }
    cout << endl;
  }
}
void figure::print_isosceles_triangle() {
  for (int i = 0; i <= height; i++) {
    for (int j = 0; j < ceil((width / 2 - ceil(i / (height / width) / 2))); j++) cout << "  ";
    for (int j = 0; j < (i / (height / width) / 2); j++) cout << shape;
    for (int j = 0; j < trunc(i / (height / width) / 2.0001); j++) cout << shape;
    cout << endl;
  }
}
int main(void) {
  cout << "폭(가로) : ";
  float width;
  cin >> width;
  cout << "높이(세로) : ";
  float height;
  cin >> height;
  cout << "출력 모양 : ";
  char shape[10];
  cin >> shape;
  figure t; //도형 클래스
  t.Setfigure(width, height, shape);
  t.print_rectangular();
  t.print_right_triangle();
  t.print_left_triangle();
  t.print_isosceles_triangle();
  return 0;
}
