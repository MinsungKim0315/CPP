#include <iostream>
using namespace std;
class point {
private:
  int x, y; //x좌표, y좌표
public:
  bool init_pos(int x_pos, int y_pos); // x, y 값 초기화
  int get_x(); // x값 읽기
  int get_y(); // y값 읽기
  bool set_x(int x_pos); // x값 쓰기
  bool set_y(int y_pos); // y값 쓰기
};
class rectangle {
private:
  point up_left, low_right;//왼쪽 상단 좌표 1, 오른쪽 하단 좌표 2
public:
  bool init_rectangle(point p1, point p2); //두 점(p1, p2)으로 up_left, low_right 초기화
  void show_rectangle();//두 점 사이 사각형 그리기
};
int main() {
  for (;; system("pause")) {
    system("cls");
    cout << "1번 좌표를 입력하세요 (x y, 공백 구분, 범위:0~50, 종료:-1) : ";
    int x, y;
    cin >> x >> y;
    if (x == -1 || y == -1) break;
    point pos1;
    if (!pos1.init_pos(x, y)) { cout << "pos1 초기화 실패" << endl; continue; }
    cout << "2번 좌표를 입력하세요 (x y, 공백 구분, 범위:0~50, 종료:-1) : ";
    cin >> x >> y;
    if (x == -1 || y == -1) break;
    point pos2;
    if (!pos2.init_pos(x, y)) { cout << "pos2 초기화 실패" << endl; continue; }
    rectangle rec1;
    if (!rec1.init_rectangle(pos1, pos2)) { cout << "rec1 초기화 실패" << endl; continue; }
    rec1.show_rectangle();
  }
  return 0;
}
bool point::init_pos(int x_pos, int y_pos) {
  if (0 > x_pos || 50 < x_pos) { cout << "X좌표 범위를 벗어났습니다.(0~50)" << endl; return false; }
  if (0 > y_pos || 50 < y_pos) { cout << "Y좌표 범위를 벗어났습니다.(0~50)" << endl; return false; }
  x = x_pos;
  y = y_pos;
  return true;
}
int point::get_x() { return x; }
int point::get_y() { return y; }
bool point::set_x(int x_pos) {
  if (0 > x_pos || 50 < x_pos) { cout << "X좌표 범위를 벗어났습니다.(0~50)" << endl; return false; }
  x = x_pos;
  return true;
}
bool point::set_y(int y_pos) {
  if (0 > y_pos || 50 < y_pos) { cout << "Y좌표 범위를 벗어났습니다.(0~50)" << endl; return false; }
  y = y_pos;
  return true;
}
bool rectangle::init_rectangle(point p1, point p2) {
  if ((p1.get_x() == p2.get_x()) || (p1.get_y() == p2.get_y())) return false;
  if (p1.get_x() > p2.get_x()) { low_right.set_x(p1.get_x());  up_left.set_x(p2.get_x()); }
  else { up_left.set_x(p1.get_x()); low_right.set_x(p2.get_x()); }
  if (p1.get_y() > p2.get_y()) { up_left.set_y(p1.get_y()); low_right.set_y(p2.get_y()); }
  else { low_right.set_y(p1.get_y()); up_left.set_y(p2.get_y()); }
  return true;
}
void rectangle::show_rectangle() {
  for (int i = 0; i < 50 - (up_left.get_y() + 1); i++) cout << endl;
  for (int i = 0; i < up_left.get_x(); i++) cout << "  ";
  cout << up_left.get_x() << "," << up_left.get_y() << endl;

  for (int i = 0; i < up_left.get_y() - low_right.get_y(); i++) {
    for (int j = 0; j < up_left.get_x(); j++) cout << "  ";
    for (int j = 0; j < low_right.get_x() - up_left.get_x(); j++) cout << "■";
    cout << endl;
  }

  for (int i = 0; i < low_right.get_x(); i++) cout << "  ";
  cout << low_right.get_x() << "," << low_right.get_y() << endl;
  for (int i = 0; i < low_right.get_y() - 1; i++) cout << endl;
}
