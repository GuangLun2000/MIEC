#include<iostream>
#include<cmath>

using namespace std;

// ������ѧ����pi
#define pi 3.1415926

// �����������Area
class Area {
public:
    virtual double getarea() = 0;
};

// �����������Volume
class Volume {
public:
    virtual double getvolume() = 0;
};

// ��������CircleԲ��
class Circle : public Area {
public:
    friend class Cylinder;

    friend class Cone;

    friend class Sphere;

    Circle() {}

    Circle(double r_) { r = r_; }

    virtual double getarea() { return pi * r * r; }

private:
    double r;
};

// ����Բ����
class Cylinder : public Circle, public Volume {
public:
    Cylinder() : Circle() {}

    Cylinder(double r_, double h_) : Circle(r_) { h = h_; }

    virtual double getarea() { return 2 * pi * r * r + 2 * pi * r * h; }

    virtual double getvolume() { return pi * r * r * h; }

private:
    double h;
};

// ����Բ׶��
class Cone : public Circle, public Volume {
public:
    Cone() : Circle() {}

    Cone(double r_, double h_) : Circle(r_) { h = h_; }

    virtual double getarea() { return pi * r * r + 2 * pi * r * sqrt(h * h + r * r) / 2; }

    virtual double getvolume() { return pi * r * r * h / 3; }

private:
    double h;
};

// ��������
class Sphere : public Circle, public Volume {
public:
    Sphere() : Circle() {}

    Sphere(double r_) : Circle(r_) {}

    virtual double getarea() { return 4 * pi * r * r; }

    virtual double getvolume() { return 4 * pi * r * r * r / 3; }
};

int main() {
    Circle circle(2);
    cout << "����һ��Բ����" << endl;
    cout << "�뾶 ��2.0" << endl;
    cout << "��� ��" << circle.getarea() << endl << endl;

    Cylinder cylinder(2, 3);
    cout << "����һ��Բ������" << endl;
    cout << "�뾶 ��2.0" << endl;
    cout << "�߶� ��3.0" << endl;
    cout << "��� ��" << cylinder.getarea() << endl;
    cout << "��� ��" << cylinder.getvolume() << endl << endl;

    Cone cone(2, 3);
    cout << "����һ��Բ׶����" << endl;
    cout << "�뾶 ��2.0" << endl;
    cout << "�߶� ��3.0" << endl;
    cout << "��� ��" << cone.getarea() << endl;
    cout << "��� ��" << cone.getvolume() << endl << endl;

    Sphere sphere(2);
    cout << "����һ�������" << endl;
    cout << "�뾶 ��2.0" << endl;
    cout << "��� ��" << sphere.getarea() << endl;
    cout << "��� ��" << sphere.getvolume() << endl << endl;
    return 0;
}

