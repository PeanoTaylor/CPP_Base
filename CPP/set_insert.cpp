#include <iostream>
#include <set>
using namespace std;

void visitSet(set<int> &box){
    for(const auto e : box){
        cout << e << " ";
    }
    cout << endl;
}

void test1(){
    set<int> box;
    box.insert(1);
    pair<set<int>::iterator,bool> result = box.insert(2);
    if(result.second){
        cout << "insert success" << endl;
        cout << *(result.first) << endl;// 指向插入元素的迭代器
    }else{
        cout << "insert fail" << endl;
    }
    visitSet(box);
}

void test2(){
    pair<string,int> p = {"age",20};
    cout << p.first << endl;
    cout << p.second << endl;
}

// 批量插入
void test3()
{
    set<int> box;
    // 初始化列表进行批量插入
    box.insert({1,2,3,4,5});
    visitSet(box);

    set<int> box2;
    box2.insert(box.begin(), box.end());
    visitSet(box2);
    /* box2[0];//没有下标访问运算 */
}
int main()
{
    test3();
    return 0;
}

