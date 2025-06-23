#include <iostream>
#include <cstring>
using namespace std;

class Student{
public:
    Student(int id, double height, const char *name, double score);

    void print();// 打印信息

private:
    int m_id;
    double m_height;
    char m_name[20];
    double m_score;
};

Student::Student(int id, double height, const char *name, double score)
    :m_id(id)
    ,m_height(height)
    ,m_score(score)
{
    strcpy(m_name,name);
    print();
}
void Student::print(){
    cout << m_id << ":" << m_height << ":" << m_name << ":" << m_score << endl;
}

int main(int argc,char *argv[])
{
    Student student1(1,111,"zhangsan",100);

    Student student2(2,222,"lisi",90);

    Student student3(3,333,"wangwu",80);
    return 0;
}

