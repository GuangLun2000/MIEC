#include<iostream>
#include <cstring>
#include<algorithm>

using namespace std;

class Employee {
private:
    //��š������ʡ������ʱ��
    int id;
    double payRate;
    double maxWorkHours;
public:

    //��������ͨ��Ա����SetData()��updatadata()��Disp()���ֱ����ڸ����ݳ�Ա��ֵ�����º������
    void setdata(int i, double p, double m) {
        id = i;
        payRate = p;
        maxWorkHours = m;
    }

    Employee updatadata(Employee employee, int i, double p, double m) {
        employee.id = i;
        employee.payRate = p;
        employee.maxWorkHours = m;
        return employee;
    }

    void display() {
        cout << "id:" << id << "\tpay rate:" << payRate << "\tmax work hours:" << maxWorkHours << endl;
    }


};

int main() {

    cout << "������������Ա����Ϣ" << endl;
    Employee employee[3];
    for (int i = 0; i < 3; i++) {
        int id;
        double payRate, maxWorkHours;
        cin >> id >> payRate >> maxWorkHours;
        employee[i].setdata(id, payRate, maxWorkHours);
    }
    employee[1].display();
    for (int j = 0; j < 3; j++) {
        employee[j].display();
    }

}
