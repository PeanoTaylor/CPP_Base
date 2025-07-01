#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

class Person
{
public:
    // 无参构造
    Person() = default;
    // 构造函数
    Person(int age, const char *name)
        : m_age(age)
    {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    // 拷贝构造函数
    Person(const Person &rhs)
    {
        if (this != &rhs)
        { // 防止自赋值
            m_age = rhs.m_age;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
        }
    }

    // 拷贝运算符重载
    Person &operator=(const Person  &rhs){
        if(this != &rhs){
            delete [] m_name;
            m_name = nullptr;

            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
        }
        return *this;
    }
    // 析构函数
    ~Person()
    {
        if (m_name)
        {
            delete[] m_name;
            m_name = nullptr;
        }
    }

    int getAge() const { return m_age; }

    const char *getName() const { return m_name; }

    // 成员函数
    void display()
    {
        cout << "name: " << m_name << " age: " << m_age << endl;
    }

private:
    // 成员变量
    int m_age;
    char *m_name;
};

class Employee : public Person
{
public:
    Employee() = default;
    // 构造函数
    Employee(const char *name, int age, const char *department, int salary) : Person(age, name), m_salary(salary)
    {
        m_department = new char[strlen(department) + 1];
        strcpy(m_department, department);
    }
    // 拷贝构造函数
    Employee(const Employee &rhs) : Person(rhs), m_salary(rhs.m_salary)
    {
        if (this != &rhs)
        {
            m_salary = rhs.m_salary;
            m_department = new char[strlen(rhs.m_department) + 1];
            strcpy(m_department, rhs.m_department);
        }
    }

    // 赋值运算符重载
    Employee& operator=(const Employee& rhs)
    {
        if (this != &rhs) {
            Person::operator=(rhs); 
            delete[] m_department;
            m_department = nullptr;
            m_department = new char[strlen(rhs.m_department) + 1];
            strcpy(m_department, rhs.m_department);
            m_salary = rhs.m_salary;
        }
        return *this;
    }
    // 析构函数
    ~Employee()
    {
        if (m_department)
        {
            delete[] m_department;
            m_department = nullptr;
        }
    }


    // 成员函数打印信息
    void display()
    {
        cout << left
             << setw(10) << "Name:" << setw(15) << getName()
             << setw(10) << "Age:" << setw(5) << getAge()
             << setw(15) << "Department:" << setw(15) << m_department
             << setw(10) << "Salary:" << m_salary << endl;
    }

private:
    int m_salary;
    char *m_department;
};

int main()
{
    Employee p1("zhangsan", 20, "C++", 5000);
    Employee p2("lisi", 30, "JAVA", 10000);
    Employee p3("wangwu", 40, "PYTHON", 15000);
    Employee p4 = p3;

    vector<Employee> employees;
    employees.push_back(p1);
    employees.push_back(p2);
    employees.push_back(p3);
    employees.push_back(p4);

    for (auto &e : employees)
    {
        e.display();
    }
    return 0;
}
