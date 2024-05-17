#include <iostream>
#include <iomanip>
using namespace std;
int main() {

  //auto 타입 추론 규칙
  //(컴파일 과정에서 초기화할 때 우변으로 좌변 타입이 결정)

  int          N = 10;
  int&        RN =  N;
  int*        pN = &N;
  const int   CN =  N;
  const int& CRN =  N;

  cout << "  N : " << setw(20) <<   N << " " <<   &N << " " << typeid(  N).name() << endl;
  cout << " RN : " << setw(20) <<  RN << " " <<  &RN << " " << typeid( RN).name() << endl;
  cout << " pN : " << setw(20) <<  pN << " " <<  &pN << " " << typeid( pN).name() << endl;
  cout << " CN : " << setw(20) <<  CN << " " <<  &CN << " " << typeid( CN).name() << endl;
  cout << "CRN : " << setw(20) << CRN << " " << &CRN << " " << typeid(CRN).name() << endl << endl;

  // 값 추론 : 우변의 값을 저장 할 수 있는 자료형 할당
  auto  A1 =  10;  // auto = int  A1 = int
  auto  A2 =   N;  // auto = int  A2 = int
  auto  A3 =  RN;  // auto = int  A3 = int
  auto  A4 =  pN;  // auto = int  A4 = int*
  auto  A5 =  CN;  // auto = int  A5 = int
  auto  A6 = CRN;  // auto = int  A6 = int

  cout << " A1 : " << setw(20) << A1 << " " << &A1 << " " << typeid(A1).name() << endl;
  cout << " A2 : " << setw(20) << A2 << " " << &A2 << " " << typeid(A2).name() << endl;
  cout << " A3 : " << setw(20) << A3 << " " << &A3 << " " << typeid(A3).name() << endl;
  cout << " A4 : " << setw(20) << A4 << " " << &A4 << " " << typeid(A4).name() << endl;
  cout << " A5 : " << setw(20) << A5 << " " << &A5 << " " << typeid(A5).name() << endl;
  cout << " A6 : " << setw(20) << A6 << " " << &A6 << " " << typeid(A6).name() << endl << endl;

  // 참조 추론 : 같은 메모리를 공유하는 참조 생성
  //auto&  A1 = 10;    // 상수 참조 불가능
  const auto& RA1 =  10;  // auto = int  RA1 = const int  (임시 값은 메모리 할당)
  auto&       RA2 =   N;  // auto = int  RA2 = int&
  auto&       RA3 =  RN;  // auto = int  RA3 = int&
  auto&       RA4 =  pN;  // auto = int  RA4 = int*&
  auto&       RA5 =  CN;  // auto = int  RA5 = const int&
  auto&       RA6 = CRN;  // auto = int  RA6 = const int&

  cout << "RA1 : " << setw(20) << RA1 << " " << &RA1 << " " << typeid(RA1).name() << endl;
  cout << "RA2 : " << setw(20) << RA2 << " " << &RA2 << " " << typeid(RA2).name() << endl;
  cout << "RA3 : " << setw(20) << RA3 << " " << &RA3 << " " << typeid(RA3).name() << endl;
  cout << "RA4 : " << setw(20) << RA4 << " " << &RA4 << " " << typeid(RA4).name() << endl;
  cout << "RA5 : " << setw(20) << RA5 << " " << &RA5 << " " << typeid(RA5).name() << endl;
  cout << "RA6 : " << setw(20) << RA6 << " " << &RA6 << " " << typeid(RA6).name() << endl << endl;

  // decltype( name ) : name과 같은 자료형으로 할당 ( 참조 변수 가능 )
  decltype(RA1)  AD1 =  50;  // decltype(RA1)  = const int&
  decltype(RA2)  AD2 =   N;  // decltype(RA2)  = int&
  decltype(RA3)  AD3 =  RN;  // decltype(RA3)  = int&
  decltype(RA4)  AD4 =  pN;  // decltype(RA4)  = int*&
  decltype(RA5)  AD5 =  CN;  // decltype(RA5)  = const int&
  decltype(RA6)  AD6 = CRN;  // decltype(RA6)  = const int&

  // decltype( auto ) : 우변과 같은 자료형으로 할당
  decltype(auto) DA1 = AD1;  // decltype(auto) = const int&
  decltype(auto) DA2 = AD2;  // decltype(auto) = int&
  decltype(auto) DA3 = AD3;  // decltype(auto) = int&
  decltype(auto) DA4 = AD4;  // decltype(auto) = int*&
  decltype(auto) DA5 = AD5;  // decltype(auto) = const int&
  decltype(auto) DA6 = AD6;  // decltype(auto) = const int&

  cout << "AD1 : " << setw(20) << AD1 << " " << &AD1 << " " << typeid(AD1).name() << endl;
  cout << "AD2 : " << setw(20) << AD2 << " " << &AD2 << " " << typeid(AD2).name() << endl;
  cout << "AD3 : " << setw(20) << AD3 << " " << &AD3 << " " << typeid(AD3).name() << endl;
  cout << "AD4 : " << setw(20) << AD4 << " " << &AD4 << " " << typeid(AD4).name() << endl;
  cout << "AD5 : " << setw(20) << AD5 << " " << &AD5 << " " << typeid(AD5).name() << endl;
  cout << "AD6 : " << setw(20) << AD6 << " " << &AD6 << " " << typeid(AD6).name() << endl << endl;

  cout << "DA1 : " << setw(20) << DA1 << " " << &DA1 << " " << typeid(DA1).name() << endl;
  cout << "DA2 : " << setw(20) << DA2 << " " << &DA2 << " " << typeid(DA2).name() << endl;
  cout << "DA3 : " << setw(20) << DA3 << " " << &DA3 << " " << typeid(DA3).name() << endl;
  cout << "DA4 : " << setw(20) << DA4 << " " << &DA4 << " " << typeid(DA4).name() << endl;
  cout << "DA5 : " << setw(20) << DA5 << " " << &DA5 << " " << typeid(DA5).name() << endl;
  cout << "DA6 : " << setw(20) << DA6 << " " << &DA6 << " " << typeid(DA6).name() << endl << endl;
  
  N = 20; // 값이 바뀌는 변수 이름은??

  return 0;
}
