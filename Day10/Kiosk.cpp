#include <iostream>
#include <string>
#include <list>
using namespace std;
void input(int& value) {
    while (!(cin >> value)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Please enter again. : ";
    }
    while (cin.get() != '\n');
}
class menu {
protected:
    string product;
    int price;
    string size;
    bool packaging;
public:
    menu(string _product = "water", int _price = 0, string _size = "Tall", bool _packaging = false) //default parameter
        :product(_product), price(_price), size(_size), packaging(_packaging) {}
    static void ShowMenu(int& menu) {   //객체 없이 사용하기 위함
        system("cls");
        cout << " [ Mega Kiosk ] \n";
        cout << " 1. Coffee \n";
        cout << " 2. Frappe \n";
        cout << " 3. Ade \n";
        cout << " 4. Dessert \n";
        cout << " 5. Total \n";
        cout << "10. Exit \n";
        cout << "Enter the menu. : ";
        input(menu);
    }
    virtual const int getprice() const { return price; }
    virtual void order() {
        cout << "상 품 명 : " << product << endl;
        cout << "가    격 : " << price << endl;
        cout << "크    기 : " << size << endl;
        cout << "포    장 : " << ((packaging == true) ? "○ \n" : "Ｘ \n");
    }
};
class coffee : public menu {
protected:
    int shot;
    string variety;  //커피 품종 Arabica, Robusta, Liberica
public:
    coffee(string _product = "Americano", int _price = 1500, string _size = "Tall", bool _packaging = false, string _variety = "Arabica", int _shot = 2)
        :menu(_product, _price, _size, _packaging), variety(_variety), shot(_shot) {}
    static void ShowMenu(int& menu) {
        system("cls");
        cout << " [ Mega Kiosk ] \n";
        cout << " 1. Americano \n";
        cout << " 2. Cappuccino \n";
        cout << " 3. Coldbrew \n";
        cout << " 4. CafeMocha \n";
        cout << "10. Previous menu... \n";
        cout << "Enter the menu. : ";
        input(menu);
    }
    virtual void order() {
        menu::order();  //menu에 있는 order정보 가져오기
        cout << "샷    수 : " << shot << endl;
        cout << "커피품종 : " << variety << endl << endl;
    }
};
class Topping {
private:
    string product;
    int price;
public:
    Topping(string _product = "Whipping Cream", int _price = 500)
        :product(_product), price(_price) {}
    static void ShowMenu(int& menu) {
        system("cls");
        cout << " [ Mega Kiosk ] \n";
        cout << " 1. Whipping Cream \n";
        cout << " 2. Cubed Cheese \n";
        cout << " 3. Jolly Pong \n";
        cout << " 4. Cookies and Cream \n";
        cout << "10. Previous menu... \n";
        cout << "Enter the menu. : ";
        input(menu);
    }
    virtual const int getprice() const { return price; }
    virtual void info() {
        cout << "추가토핑 : " << product << endl;
        cout << "추가요금 : " << price << endl << endl;
    }
};
class frappe : public menu {
protected:
    Topping* topping; //토핑
public:
    frappe(string _product = "Real chocolate frappe", int _price = 3900, string _size = "Tall", bool _packaging = false, Topping* _topping = nullptr)
        :menu(_product, _price, _size, _packaging), topping(_topping) {}
    ~frappe() { if (topping != nullptr) delete topping; }   //포인터 멤버가 있기 때문에
    static void ShowMenu(int& menu) {
        system("cls");
        cout << " [ Mega Kiosk ] \n";
        cout << " 1. Real chocolate frappe \n";
        cout << " 2. Plain pongcrush \n";
        cout << " 3. Strawberry Cheeseholic \n";
        cout << " 4. Unicorn frappe \n";
        cout << "10. Previous menu... \n";
        cout << "Enter the menu. : ";
        input(menu);
    }
    void setTopping(Topping* _topping) { if (topping != nullptr) delete topping; topping = _topping; }
    virtual void order() {
        menu::order();
        topping->info();
    }
};
class ade : public menu {
protected:
    string fruit; // 
public:
    ade(string _product = "Cherry Coke", int _price = 3000, string _size = "Tall", bool _packaging = false, string _fruit = "cherry")
        :menu(_product, _price, _size, _packaging), fruit(_fruit) {}
    static void ShowMenu(int& menu) {
        system("cls");
        cout << " [ Mega Kiosk ] \n";
        cout << " 1. Ice Tea \n";
        cout << " 2. Cherry Coke \n";
        cout << " 3. Blue lemonade \n";
        cout << " 4. Grapefruit Honey Black tea \n";
        cout << "10. Previous menu... \n";
        cout << "Enter the menu. : ";
        input(menu);
    }
    virtual void order() {
        menu::order();
        cout << "과    일 : " << fruit << endl << endl;
    }
};
class dessert : public menu {
protected:
    string category; // 종류 구분
public:
    dessert(string _product = "Plain croiffle", int _price = 2500, string _size = "Tall", bool _packaging = false, string _category = "Bread")
        :menu(_product, _price, _size, _packaging), category(_category) {}
    static void ShowMenu(int& menu) {
        system("cls");
        cout << " [ Mega Kiosk ] \n";
        cout << " 1. Plain croiffle \n";
        cout << " 2. Tiramisu Cake \n";
        cout << " 3. Earl Grey Pound \n";
        cout << " 4. Potato bread \n";
        cout << "10. Previous menu... \n";
        cout << "Enter the menu. : ";
        input(menu);
    }
    virtual void order() {
        menu::order();
        cout << "분    류 : " << category << endl << endl;
    }
};
class customer {
private:
    static unsigned long orderNum;
    string name;
    string phone;
    long totalPrice;
    list<menu*>menulist;    //장바구니 역할
public:
    customer(string _name = "Mega", string _phone = "010-0000-0000") :name(_name), phone(_phone), totalPrice(0) { orderNum++; menulist.clear(); }
    ~customer() { for (auto& i : menulist) delete i; }
    void login() {
        cout << " [ 메가 커피 Kiosk ] \n";
        cout << " (이름과 연락처를 남겨주세요.) \n";
        cout << "이    름 : ";
        getline(cin, name);
        cout << "연 락 처 : ";
        getline(cin, phone);
    }
    void info() {
        cout << "주문번호 : " << orderNum << endl;
        cout << "이    름 : " << name << endl;
        cout << "연 락 처 : " << phone << endl << endl;
    }
    void totalmenu() { for (auto& itr : menulist) itr->order(); }
    void addmenu(menu* item) {
        menulist.push_back(item);
        totalPrice += item->getprice();
    }
    const int totalprice() const { return totalPrice; }


};
unsigned long customer::orderNum;
int main() {
    int menu1 = 0, menu2 = 0, menu3 = 0;
    customer* Neworder = new customer;
    Neworder->login();
    while (1) {
        menu::ShowMenu(menu1);
        switch (menu1) {
        case 1:
            coffee::ShowMenu(menu2);
            switch (menu2) {
            case 1: Neworder->addmenu(new coffee("Americano", 1500, "Tall", true, "Arabica", 2)); break;
            case 2: Neworder->addmenu(new coffee("Cappuccino", 2700, "Grande", false, "Robusta", 4)); break;
            case 3: Neworder->addmenu(new coffee("Coldbrew", 3300, "Venti", true, "Robusta", 10)); break;
            case 4: Neworder->addmenu(new coffee("CafeMocha", 3700, "Grande", false, "Liberica", 6)); break;
            }
            break;
        case 2: {
            frappe::ShowMenu(menu2);
            menu* choice = nullptr;
            switch (menu2) {
            case 1: choice = new frappe("Real chocolate frappe", 3900, "Tall", false); break;
            case 2: choice = new frappe("Plain pongcrush", 3900, "Grande", true); break;
            case 3: choice = new frappe("Strawberry Cheeseholic", 4500, "Venti", true); break;
            case 4: choice = new frappe("Unicorn frappe", 4800, "Grande", false); break;
            default: continue;
            }
            Topping::ShowMenu(menu3);
            Topping* topping = nullptr;
            switch (menu3) {
            case 1: topping = new Topping("Whipping Cream", 500); break;
            case 2: topping = new Topping("Cubed Cheese", 1000); break;
            case 3: topping = new Topping("Jolly Pong", 1500); break;
            case 4: topping = new Topping("Cookies and Cream", 2000); break;
            }
            frappe* beverage = (frappe*)choice; //Down Casting
            beverage->setTopping(topping);
            Neworder->addmenu(choice);
        }break;
        case 3:
            ade::ShowMenu(menu2);
            switch (menu2) {
            case 1: Neworder->addmenu(new ade("Ice Tea", 2500, "Grande", true, "Peach")); break;
            case 2: Neworder->addmenu(new ade("Cherry Coke", 3000, "Tall", false, "Cherry")); break;
            case 3: Neworder->addmenu(new ade("Blue Lemonade", 3500, "Venti", false, "Lemon")); break;
            case 4: Neworder->addmenu(new ade("Grapefruit Honey Blacktea", 3500, "Tall", true, "Grapefruit")); break;
            }
            break;
        case 4:
            dessert::ShowMenu(menu2);
            switch (menu2) {
            case 1: Neworder->addmenu(new dessert("Plain croiffle", 2500, "", true, "Bread")); break;
            case 2: Neworder->addmenu(new dessert("Tiramisu Cake", 3000, "", false, "Cake")); break;
            case 3: Neworder->addmenu(new dessert("Earl Grey Pound", 3500, "", true, "Bread")); break;
            case 4: Neworder->addmenu(new dessert("Potato bread", 3500, "", false, "Bread")); break;
            }
            break;
        case 5:
            Neworder->info();
            Neworder->totalmenu();
            cout << "총 금액 : " << Neworder->totalprice() << " 원 입니다. \n";
            system("pause");
            delete Neworder;
            Neworder = new customer;
            system("cls");
            Neworder->login();
            break;
        case 10:
            cout << "\n\n [ 프로그램 종료 합니다. ] \n\n\n";
            exit(0);
        }
    }
    return 0;
}
