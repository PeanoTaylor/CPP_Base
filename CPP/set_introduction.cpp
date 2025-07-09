#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

/*
 * set: 底层使用红黑树
 * 特点:
 * 1.存储的数据是有序的 默认升序排列
 * 2.存储的是单列数据
 * 3.数据不能进行重复
 *
 * 使用: 需要指明容器中存放什么类型的数据
 * set<int> box;
 */

void visitSet(set<int> & box)
{
    for(auto e : box)
    {
        cout << e << " ";
    }
    cout << endl;
}

// set容器的构建
void test1()
{
    // 无参构造函数 
    set<int> box1;
    // 通过初始化列表方式构建
    /* set<int> box2 { 3,1,2,5,4,1 }; */
    set<int> box2 { 3,1,2,5,4};
    visitSet(box2);
    // 通过迭代器方式构建
    auto itBegin = box2.begin();
    set<int>::iterator itEnd = box2.end();
    set<int> box3 { itBegin, --itEnd };
    visitSet(box3);
    // 通过拷贝构造函数构建
    set<int> box4 = box2;
    visitSet(box4);
}

int main(int argc, char * argv[])
{
    test1();
    return 0;
}

