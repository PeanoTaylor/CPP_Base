#include <iostream>
#include <cstring>
using namespace std;

class Student{
public:
    // 构造函数
    Student(int id, const char *name, int age)
    : m_id(id)
    , m_name(nullptr)
    , m_age(age){
        m_name = new char[strlen(name) + 1];
        strcpy(m_name,name);    
    }

    // 拷贝构造函数
    Student(const Student & rhs)
    : m_id(rhs.m_id)
    , m_name(nullptr)
    , m_age(rhs.m_age)
    {   
        m_name = new char[strlen(rhs.m_name) + 1];
        strcpy(m_name,rhs.m_name);
        cout << "拷贝构造函数被调用" << endl;
    }
    // 析构函数
    ~Student(){
        delete[] m_name;
    }
    // 赋值运算符重载
    Student &operator = (const Student &rhs){
        if(this != &rhs){
            this->m_id = rhs.m_id;
            // 释放旧内存
            delete[] m_name;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(this->m_name,rhs.m_name);
            this->m_age = rhs.m_age;
        }
        return *this;
    }

    void print(){
        cout << "学号:" << m_id << " 姓名:" << m_name << " 年龄:" << m_age << endl;
    }

    void setId(int id){
        m_id = id;
    }

    void setName(const char *name){
        delete[] m_name;

        m_name = new char[strlen(name) + 1];
        strcpy(m_name,name);
    }

    void setAge(int age){
        m_age = age;
    }

private:
    int m_id;
    char *m_name;
    int m_age;
};

int main(int argc,char *argv[])
{
    Student stu1(1,"zhangsan",20);
    stu1.print();

    Student stu2 = stu1;
    stu2.print();
    return 0;
}

