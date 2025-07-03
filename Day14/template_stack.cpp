#include <iostream>
using namespace std;

template <typename T>
class Stack
{
public:
    // 构造函数
    Stack(int size) : m_maxSize(size), m_topIndex(-1)
    {
        m_elements = new T[m_maxSize];
    }
    // 析构函数
    ~Stack()
    {
        delete[] m_elements;
    }
    // 压栈
    bool push(const T &value)
    {
        if (m_topIndex >= m_maxSize - 1)
        {
            cout << "stack overflow" << endl;
            return false;
        }
        m_elements[++m_topIndex] = value;
        return true;
    }
    // 出栈
    bool pop()
    {
        if (m_topIndex < 0)
        {
            cout << "stack empty" << endl;
            return false;
        }
        --m_topIndex;
        return true;
    }
    // 获取栈顶元素
    T top() const
    {
        if (m_topIndex < 0)
        {
            cout << "stack empty" << endl;
            return T();
        }
        return m_elements[m_topIndex];
    }
    // 判空
    bool empty() const
    {
        if (m_topIndex == -1)
        {
            return true;
        }
        return false;
    }
    // 获取元素数量
    int size() const
    {
        return m_topIndex + 1;
    }

private:
    int m_maxSize;
    int m_topIndex;
    T *m_elements; // 动态数组存放元素
};

int main()
{
    Stack<string> s1(10);

    s1.push("h");
    s1.push("e");
    s1.push("l");
    s1.push("l");
    s1.push("o");
    s1.push("!");

    s1.pop();

    cout << s1.top() << endl;

    cout << s1.size() << endl;
    return 0;
}
