#include <iostream>
void cinclear() { // 입력 객체 초기화 함수
  // 입력 객체 실패의 경우 초기화
  if (std::cin.fail()) std::cin.clear();
  // 버퍼 비우기 (비워진 경우 Enter 입력)
  while (std::cin.get() != '\n');
}
int main() {
    std::cout << "두 수 입력 : ";
    int a, b;
    std::cin >> a >> b;
    cinclear();
    std::cout << "입력결과 : " << a << ", " << b << std::endl;
    return 0;
}
