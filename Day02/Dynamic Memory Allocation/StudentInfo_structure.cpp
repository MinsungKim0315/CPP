#include <iostream>
#include <cstring>
using namespace std;
struct STU {
    char* name, * phone;
};
int main() {
    int in;
    cout << "학생수 입력 : ";
    cin >> in;
    STU* sp = new STU[in];
    for (int i = 0; i < in; i++) {
        char buf[30];
        cout << "\n이    름 : ";
        cin >> buf;
        sp[i].name = new char[strlen(buf) + 1];
        strcpy_s(sp[i].name,strlen(buf)+1, buf);
        cout << "이름 할당 완료 ";
        cout << sp[i].name << endl;
        cout << "전화번호 : ";
        cin >> buf;
        sp[i].phone = new char[strlen(buf) + 1];
        strcpy_s(sp[i].phone, strlen(buf) + 1, buf);
        cout << "번호 할당 완료 ";
        cout << sp[i].phone << endl;
    }
    for (int i = 0; i < in; i++) {
        delete[] sp[i].name;
        cout << i << "이름 할당 해제 " << endl;
        delete[] sp[i].phone;
        cout << i << "번호 할당 해제 " << endl;
    }
    delete[] sp;
    cout << "구조체 할당 해제 " << endl;
    return 0;
}
