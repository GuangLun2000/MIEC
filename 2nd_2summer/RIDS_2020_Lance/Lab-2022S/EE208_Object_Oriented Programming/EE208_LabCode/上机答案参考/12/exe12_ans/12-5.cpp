#include<iostream>
#include <cstring>
#include<algorithm>

using namespace std;

class Stud {
public:
    //��̬��������ֺܷ�����
    static double sum_score;
    static int num;

    //��������ͨ��Ա����SetData()��Disp()���ֱ����ڸ����ݳ�Ա��ֵ��������ݳ�Ա��ֵ��
    void setdata(int i, char *n, double s) {
        id = i;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        score = s;
        sum_score += score;
        num += 1;
    }

    void display() {
        cout << "id:" << id << "\tname:" << name << "\tscore:" << score << endl;
    }

    //��̬��Ա����Avg()�������ڼ���ƽ����
    static double avg() { return sum_score / num; }

private:
    //ѧ�š��������ɼ�
    int id;
    char *name;
    double score;
};

//��ʼ����̬��Ա����
double Stud::sum_score = 0;
int Stud::num = 0;

int main() {
    int ids[] = {1, 2, 3, 4, 5};
    char *stunames[] = {"Rose", "Mike", "Eve", "Micheal", "Jack"};
    double scores[] = {95, 84, 88, 64, 100};
    Stud stud[5];

    for (int i = 0; i < 5; i++)
        stud[i].setdata(ids[i], stunames[i], scores[i]);

    for (int i = 0; i < 5; i++)
        stud[i].display();

    cout << "\tsum_score:" << stud[0].sum_score << "\tavg:" << stud[0].avg() << endl;
}


