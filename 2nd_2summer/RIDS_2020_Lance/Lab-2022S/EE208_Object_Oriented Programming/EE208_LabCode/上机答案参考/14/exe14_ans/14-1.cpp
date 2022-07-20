#include<iostream>
#include <cstring>

using namespace std;

class Student {
public:
    //��Ԫ����Compare()���Ƚ�����ѧ���ɼ��ĸߵ�
    friend int compare(Student *a, Student *b);

    //��������ѧ����Ϣ
    void set(char *n, double s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        score = s;
    }

    //���ڻ�ȡѧ����Ϣ
    double getScore() { return score; }

    char *getName() { return name; }

    //��ʾѧ����Ϣ
    void display() {
        cout << "Name:" << name << "\tScore:" << score << endl;
    }

    //��������
    ~Student() {
        delete name;
    }

private:
    char *name;
    double score;
};


//1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(Student *a, Student *b) {
    if (a->getScore() > b->getScore())
        return 1;
    else if (a->getScore() == b->getScore())
        return 0;
    else
        return -1;
}

int main() {
    Student *min, *max;
    Student studs[5];
    char *stunames[] = {"Rose", "Mike", "Eve", "Micheal", "Jack"};
    double scores[] = {95, 84, 88, 64, 100};

    for (int i = 0; i < 5; i++) {
        studs[i].set(stunames[i], scores[i]);
        studs[i].display();
    }

    min = &studs[0];
    max = &studs[0];
    for (int i = 1; i < 5; i++) {
        Student *j = &studs[i];
        if (compare(min, j) == 1)
            min = j;
        if (compare(max, j) == -1)
            max = j;
    }
    cout << "The worst student : " << min->getName() << endl;
    cout << "The best student : " << max->getName() << endl;


    return 0;
}


