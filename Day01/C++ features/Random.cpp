#include <iostream>
#include <iomanip>
#include <random>
// mt19937_64, random_device, uniform_int_distribution
using namespace std;
int main() {
    random_device rd;   // 하드웨어 리소스 기반 난수 발생기
    mt19937_64 gen(rd());  //  64비트 메르센 트위스터 엔진 생성
    uniform_int_distribution<int> dist(-100, 100);
    // -100 <= x <= 100 범위의 균일한 정수 값 분포를 생성
    for (int i = 0; i < 5; ++i) {
        cout << setw(5) << dist(gen)
            << setw(25) << gen()
            << setw(15) << rd() << endl;
    }
}
