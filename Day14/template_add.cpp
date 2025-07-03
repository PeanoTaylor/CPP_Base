#include <iostream>
#include <set>
using namespace std;

// 函数模板：普通加法（适用于int、double等）
template <typename T>
T add(T x, T y)
{
    return x + y;
}

// 函数模板特化：针对set<int>实现集合合并
template <>
set<int> add<set<int>>(set<int> s1, set<int> s2)
{
    set<int> result = s1;
    result.insert(s2.begin(), s2.end()); // 合并s2的所有元素到result
    return result;
}

int main()
{
    set<int> s1 = {1, 3, 5};
    set<int> s2 = {2, 3, 4};
    set<int> s3 = add(s1, s2);
    cout << add(1, 2) << endl;
    cout << add(1.5, 2.3) << endl;
    cout << "set<int> merged: ";
    for (int x : s3)
        cout << x << " ";
    cout << endl;
    return 0;
}
