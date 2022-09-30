#include <iostream>

#include <string>

using namespace std;

class Toy {
public:
    Toy(string name, int money, string addr) {
        this->name = name;
        this->money = money;
        this->addr = addr;
    }

    string getname() { return name; }

    int getmoney() {
        return (int) (money * discount);
    }

    string getaddress() { return addr; }

    void getdiscount(float discount) {
        this->discount = discount;
    }

    void print() {
        cout << "�۸�:" << getname() << ": " << getmoney() << ",����:" << getaddress() << endl;
    }

private:
    string name;
    int money;
    string addr;
    float discount = 1.0;
};

int main(void) {
    Toy T1("���ν��", 500, "make in china");
    float discount;
    T1.print();
    cout << "����:";
    cin >> discount;
    T1.getdiscount(discount);
    T1.print();


}

