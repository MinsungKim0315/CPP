#include <iostream>
using namespace std;
namespace A {
    void BUBLE() {
        cout << "A::BUBLE\n";
    }
    void pop() {
        cout << "A::POP!\n";
    }
}
namespace B {
    void BUBLE() {
        cout << "B::BUBLE\n";
    }
    void pop() {
        cout << "B::POP!\n";
    }
}
using namespace B;
int main() {
    A::BUBLE();
    BUBLE();
    A::pop();
    pop();
    return 0;
}
