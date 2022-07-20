#include<iostream>
#include<math.h>

using namespace std;

class Tri {
    double a, b, c;  //���������ε�����
public:
    Tri(double x, double y, double z) //���캯������ʼ������
    {
        a = x;
        b = y;
        c = z;
    }

    double getperimeter()  //���������ε��ܳ�
    { return (a + b + c); }

    double getarea()  //���������ε����
    {
        double s = getperimeter() / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }

    void output() //��������εĲ���
    {
        cout << "�����εı߳�:" << a << ' ' << b << ' ' << c << endl;
        cout << "�����ε��ܳ�:" << getperimeter() << endl;
        cout << "�����ε����:" << getarea() << endl << endl;
    }

};//��������Ķ�������������������εĸ������ԺͿ�ʵʩ�Ĳ���

int main() {
    double x, y, z;
    cin >> x >> y >> z;
    Tri tri(x, y, z);

    if (x + y > z && y + z > x && x + z > y)
        tri.output();  //��������������εĲ���
    else
        cout << "������������!" << endl;

}

