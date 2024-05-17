#include <iostream> // 다양한 for(반복문) 사용
using namespace std;
int main() {
  int arr1[]{ 11, 12, 13, 14, 15, 16, 17, 18, 19 };
  for (int i = 0; i < _countof(arr1); i++) cout << arr1[i] << " "; cout << endl;
  for (int   i : arr1) i += 10, cout << i << " "; cout << endl;
  for (int&  i : arr1) i += 20, cout << i << " "; cout << endl;
  for (auto  i : arr1) i += 10, cout << i << " " << &i << endl; cout << endl;
  for (auto& i : arr1) i += 20, cout << i << " " << &i << endl; cout << endl;

  char arr2[]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
  for (char i = 0; i < _countof(arr2); i++) cout << arr2[i] << " "; cout << endl;
  for (int   i : arr2) i += 10, cout << i << " "; cout << endl;
  for (char& i : arr2) i += 32, cout << i << " "; cout << endl;
  for (auto  i : arr2) i += 5, cout << i << " " << (void*)&i << endl; cout << endl;
  for (auto& i : arr2) i += 5, cout << i << " " << (void*)&i << endl; cout << endl;

  return 0;
}
