#include <iostream>
using namespace std;

class Animal{
public:
    void eat(){
         cout << "Animal eats food." << endl;
    }

    void sleep(){
        cout << "Animal sleeps." << endl;
    }
private:
    void breath(){
        cout << "Animal breathes." << endl;
    }
};

class Dog:public Animal{
public:
    void bark() {
        cout << "Dog barks." << endl;
        sleep();
        // breath(); 私有成员无法访问
    }
};

int main()
{
    Dog dog;
    dog.eat();
    dog.sleep();
    return 0;
}

