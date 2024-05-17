#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
  cout << "학생 수 입력하세요. :";
  int std_num;
  cin >> std_num;
  int* score = new int[std_num]; // 원점수 배열 int score[std_num];
  float* variance = new float[std_num]; // 편차 제곱의 배열 float variance[std_num];
  float sum = 0, ave = 0, var = 0; // 총점, 평균, 분산
  srand((unsigned int)time(NULL));
  for (int i = 0; i < std_num; i++) {
    score[i] = rand() % 101;
    sum += score[i];
  }
  ave = sum / std_num;
  for (int i = 0; i < std_num; i++) {
    variance[i] = (score[i] - ave) * (score[i] - ave);
    var += variance[i];
    cout << "점 수 : " << setw(6) << score[i] << " 편차 제곱 : " << setw(6) << variance[i] << endl;
  }
  var /= std_num;
  cout << "총 점 : " << sum << " 평 균 : " << ave << " 분 산 : " << var << " 표준편차 : " << sqrt(var) << endl;
  delete[] score;
  delete[] variance;
  return 0;
}
