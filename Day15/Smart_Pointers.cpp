#include <iostream>
#include <memory>
using namespace std;

void test0()
{
    int *pInt = new int(10);
    auto_ptr<int> ap(pInt);
    cout << "*pInt:" << *pInt << endl;
    cout << "*ap:" << *ap << endl;
    cout << "-------" << endl;
    auto_ptr<int> ap2(ap);
    // cout << "*ap:" << *ap << endl;// 管理权已移交给ap2
    cout << "*ap2:" << *ap2 << endl;
}

void test1()
{
    unique_ptr<int> up(new int(20));
    cout << *up << endl;
    cout << up.get() << endl;
    cout << "-------" << endl;
    // 独享所有权的智能指针，对托管的空间独立拥有
    // 拷贝构造已经被删除
    // unique_ptr<int> up2 = up; // 复制操作 error

    // 赋值运算符函数也被删除
    unique_ptr<int> up3(new int(20));
    // up3 = up; // 赋值操作 error
}

void test2()
{
    shared_ptr<int> sp(new int(10));
    cout << "sp.use_count(): " << sp.use_count() << endl;

    cout << endl;
    cout << "执行复制操作" << endl;
    shared_ptr<int> sp2 = sp;
    cout << "sp.use_count(): " << sp.use_count() << endl;
    cout << "sp2.use_count(): " << sp2.use_count() << endl;

    cout << endl;
    cout << "再创建一个对象sp3" << endl;
    shared_ptr<int> sp3(new int(30));
    cout << "sp.use_count(): " << sp.use_count() << endl;
    cout << "sp2.use_count(): " << sp2.use_count() << endl;
    cout << "sp3.use_count(): " << sp3.use_count() << endl;

    cout << endl;
    cout << "执行赋值操作" << endl;
    sp3 = sp;
    cout << "sp.use_count(): " << sp.use_count() << endl;
    cout << "sp2.use_count(): " << sp2.use_count() << endl;
    cout << "sp3.use_count(): " << sp3.use_count() << endl;
}

int main()
{
    test2();
    return 0;
}
