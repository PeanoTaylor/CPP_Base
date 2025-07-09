#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

void test1()
{
    set<int> box { 2,3,1,5,4 };
    // count(目标元素)
    // 找到了 返回1
    // 没找到 饭回0
    int result = box.count(6);
    if(result)
    {
        cout << result << endl;
    }else{
        cout << "not found" << endl;
    }
}

void test2()
{
    set<int> box { 2,3,1,5,4 };
    // find(目标元素)
    // 找到了 返回该元素对应的迭代器
    // 没找到 返回的是end()
    auto it = box.find(3);
    if(it != box.end())
    {
        cout << "find success" << endl;
        cout << *it << endl;
    }else{
        cout << "not found" << endl;
    }

    set<int> box2 {box.begin(), box.find(3)};
}

int main(int argc, char * argv[])
{
    /* test1(); */
    test2();
    return 0;
}

