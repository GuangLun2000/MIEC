#include <iostream>

using namespace std;

//����Shape����
class Shape {
public:
	//���麯���������಻��ʵ������,������麯��û��ִ���壬��ô�������const=0
	virtual double perimeter() const = 0;

	//��Ԫ����
	friend bool operator<(const Shape &s1, const Shape &s2);
};

//���������ඨ��
class Triangle : public Shape {
public:
	//���캯��
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

	//���ǻ�����麯��
	double perimeter() const { return a + b + c; }

private:
	double a, b, c;
};

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : width(width), height(height) {}

	double perimeter() const { return 2 * width + 2 * height; }

private:
	double width, height;
};

class Circle : public Shape {
public:
	Circle(double radius) : radius(radius) {}

	double perimeter() const { return 2 * 3.14 * radius; }

private:
	double radius;
};

//���������
bool operator<(const Shape &s1, const Shape &s2) {
	return s1.perimeter() < s2.perimeter();
}

int main() {
	Triangle T(1.0, 2.0, 3.0);
	Rectangle R(2.0, 3.0);
	Circle C(3.0);
	cout << T.perimeter() << " " << R.perimeter() << " " << C.perimeter() << endl;

	if (T < R) cout << "True" << endl;
	else cout << "False" << endl;

	if (R < C) cout << "True" << endl;
	else cout << "False" << endl;

	if (T < C) cout << "True" << endl;
	else cout << "False" << endl;

}



