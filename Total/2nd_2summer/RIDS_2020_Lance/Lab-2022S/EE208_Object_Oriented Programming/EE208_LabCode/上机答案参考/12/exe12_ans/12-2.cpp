#include<iostream>

using namespace std;

class Box {

private:
    double m_a;//������߳�
public:
    //seta(double a)������������߳���
    void seta(double a) {
        m_a = a;
    }

    //getvolume()�����������
    double getvolume() {
        return m_a * m_a * m_a;
    }

    //getarea()������������
    double getarea() {
        return m_a * m_a * 6;
    }

    //����Display()�������������Ľ����
    void display() {
        cout << "Volume: " << getvolume() << endl;
        cout << "Area: " << getarea() << endl;
    }

};


int main() {
    Box box;
    //��box�ı߳����ó�2.5
    box.seta(2.5);
    //չʾ����ͱ�����ļ�����
    box.display();
}


