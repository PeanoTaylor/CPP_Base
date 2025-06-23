#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
public:
    bool empty();    // 判断栈是否为空
    bool full();     // 判断栈是否已满
    void push(int);  // 元素入栈
    void pop();      // 元素出栈
    int top();       // 获取栈顶元素
    Stack(): topIndex(-1) {}  // 初始化栈
private:
    static const int MAXSIZE = 5;  // 栈最大容量
    int data[MAXSIZE];  // 存储元素
    int topIndex;       // 栈顶指针
};

bool Stack::empty() {
    return topIndex == -1;
}

bool Stack::full() {
    return topIndex == MAXSIZE - 1;
}

void Stack::push(int value) {
    if (full()) {
        throw overflow_error("错误：栈已满");
    }
    data[++topIndex] = value;
}

void Stack::pop() {
    if (empty()) {
        throw underflow_error("错误：栈为空");
    }
    topIndex--;
}

int Stack::top() {
    if (empty()) {
        throw underflow_error("错误：栈为空");
    }
    return data[topIndex];
}

void test() {
    Stack s;

    // 测试empty()
    cout << "测试空栈状态: " << (s.empty() ? "通过" : "失败") << endl;

    // 测试push()和top()
    s.push(10);
    cout << "压入10后，栈顶应为10: "
         << (s.top() == 10 ? "通过" : "失败") << endl;

    // 测试empty()和full()
    cout << "当前栈不应为空: "
         << (!s.empty() ? "通过" : "失败") << endl;
    cout << "当前栈不应为满: "
         << (!s.full() ? "通过" : "失败") << endl;

    // 测试pop()
    s.pop();
    cout << "弹出元素后，栈应为空: "
         << (s.empty() ? "通过" : "失败") << endl;

    // 测试full()
    cout << "正在填满栈..." << endl;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    cout << "栈此时应为满: "
         << (s.full() ? "通过" : "失败") << endl;

    // 测试异常处理
    try {
        cout << "测试溢出..." << endl;
        s.push(10);  // 这应该抛出异常
        cout << "失败：未捕获溢出异常" << endl;
    } catch (const overflow_error& e) {
        cout << "通过：捕获到溢出异常 - " << e.what() << endl;
    }

    try {
        cout << "测试下溢..." << endl;
        Stack emptyStack;
        emptyStack.pop();  // 这应该抛出异常
        cout << "失败：未捕获下溢异常" << endl;
    } catch (const underflow_error& e) {
        cout << "通过：捕获到下溢异常 - " << e.what() << endl;
    }
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}
