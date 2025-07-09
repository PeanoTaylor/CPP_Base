#include <iostream>
using namespace std;


class Base {
public:
    int a = 1;
protected:
    int b = 2;
private:
    int c = 3;
};

class A : public Base {
    void test() {
        a = 10; //  仍是 public
        b = 20; //  protected
        // c = 30; //  无法访问
    }
};

class B : protected Base {
    void test() {
        a = 10; //  成为 protected
        b = 20; //  protected
    }
    void outside() {
        // 这里仍无法访问 a、b，因为是 protected
    }
};

class C : private Base {
    void test() {
        a = 10; //  变为 private
        b = 20; //  变为 private
    }
};

int main()
{
    
    return 0;
}

