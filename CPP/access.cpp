#include <iostream>

using std::cout;
using std::endl;
/*
 * protected继承--->千秋万代
 * private继承----->断子绝孙
 */
class Father1
{
public:
    int m_num1 = 1;
protected:
    int m_num2 = 2;
private:
    int m_num3 = 3;
};

class Son1 
: public Father1 // public继承Father1
{
public:
    void sonMethod()
    {
        m_num1;
        m_num2;
        /* m_num3; */
    }
};

class Father2
{
public:
    int m_num1 = 1;
protected:
    int m_num2 = 2;
private:
    int m_num3 = 3;
};

class Son2 
: protected Father2 // protected继承Father1
{
public:
    void sonMethod()
    {
        m_num1;
        m_num2;
        /* m_num3; */
    }
};

class GrandSon2
: protected Son2
{
public:
    void grandSonMethod()
    {
        m_num1;
        m_num2;
        /* m_num3; */
    }
};
class Father3
{
public:
    int m_num1 = 1;
protected:
    int m_num2 = 2;
private:
    int m_num3 = 3;
};

class Son3 
: private Father3 // private继承Father1
{
public:
    void sonMethod()
    {
        m_num1;
        m_num2;
        /* m_num3; */
    }
};

class GrandSon3
: private Son3
{
public:
    void grandSonMethod()
    {
        // 所有的都不能访问了
        /* m_num1; */
        /* m_num2; */
        /* m_num3; */
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

