#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

//person�ඨ��
class Person {
    //���ݳ�Ա
protected:
    char name[10];
    int age;
    char sex[10];
public:
    //���캯��
    Person(char pname[] = "", int page = 0, char psex[] = "") {
        strcpy(name, pname);
        age = page;
        strcpy(sex, psex);
    }

    //show����
    void show() const {
        cout << "����:" << name << endl;
        cout << "����:" << age << endl;
        cout << "�Ա�:" << sex << endl;

    }
};

//����Teacher��
class Teacher : public Person {
    //�������ݳ�Ա
protected:
    char title[10];

public:
    //���캯��
    Teacher(char tname[] = "", int tage = 0, char tsex[] = "", char *ttitle = "") : Person(tname, tage, tsex) {
        strcpy(title, ttitle);
    }

    //����show����
    void show() const {
        cout << "����:" << name << endl;
        cout << "����:" << age << endl;
        cout << "�Ա�:" << sex << endl;
        cout << "ְ��:" << title << endl;
    }
};

//����Cadre��
class Cadre : public Person {
    //�������ݳ�Ա
protected:
    char post[20];
    int wages;
public:
    //���캯��
    Cadre(char cname[] = "", int cage = 0, char csex[] = "", char *cpost = "", int cwages = 0) : Person(cname, cage,
                                                                                                        csex) {
        strcpy(post, cpost);
        wages = cwages;
    }

    //����show����
    void show() const {
        cout << "����:" << name << endl;
        cout << "����:" << age << endl;
        cout << "�Ա�:" << sex << endl;
        cout << "ְ��:" << post << endl;
        cout << "����:" << wages << endl;
    }
};

int main() {
    Teacher t("����", 35, "��", "������");
    Cadre c("���", 27, "Ů", "�������ʦ", 5000);
    t.show();
    c.show();
    return 0;
}

