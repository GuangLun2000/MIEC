#include<iostream>

using namespace std;

class Rectangle {
public:
    //perimeter()���㳤���ε��ܳ�
    double perimeter() { return 2 * (m_length + m_width); }

    //getarea()���㳤�������
    double getarea() { return m_length * m_width; }

    //setwidth()��GetWidth()�������ú͵õ�m_width��ֵ
    void setwidth(double w) { m_width = w; }

    double getwidth() { return m_width; }

    //setlength()��GetLength()�������ú͵õ�m_length��ֵ
    void setlength(double l) { m_length = l; }

    double getlength() { return m_length; }

    //set_()����Ӧ��֤m_length��m_width��Ϊ0.0��20.0֮��ĸ�������
    bool set_() {
        bool n = 1;
        if (0 > m_length || 20 < m_length) {
            cout << "length is not in 0.0 - 20.0" << endl;
            n = 0;
        }
        if (0 > m_width || 20 < m_width) {
            cout << "width is not in 0.0 - 20.0" << endl;
            n = 0;
        }
        if (n)
            cout << "length and width are both in 0.0 - 20.0" << endl;
        return n;
    }

private:
    //������Ա����m_length��m_width����Ĭ��ֵΪ1
    double m_length = 1;
    double m_width = 1;
};

int main() {
    Rectangle rec;
    cout << "Length : " << rec.getlength() << "    " << "Width : " << rec.getwidth() << endl;
    rec.set_();
    cout << endl << endl;

    rec.setlength(5.2);
    rec.setwidth(4);
    cout << "Length : " << rec.getlength() << "    " << "Width : " << rec.getwidth() << endl;
    rec.set_();
    cout << endl << endl;

    rec.setwidth(25);
    cout << "Length : " << rec.getlength() << "    " << "Width : " << rec.getwidth() << endl;
    rec.set_();
    cout << endl << endl;

}


