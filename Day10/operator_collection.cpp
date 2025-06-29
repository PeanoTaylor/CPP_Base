#include <iostream>
#include <cstring>
using namespace std;

class String 
{
public:
    // 默认构造函数：初始化为空字符串
	String()
    : m_pstr(new char[1]) {
        m_pstr[0] = '\0';
    }

    // 构造函数：使用 const char* 初始化
	String(const char *pstr)
    : m_pstr(new char[strlen(pstr) + 1]){
        strcpy(m_pstr, pstr);
    }

    // 拷贝构造函数：深拷贝构造
	String(const String &rhs)
    : m_pstr(new char[strlen(rhs.m_pstr) + 1]){
        strcpy(m_pstr, rhs.m_pstr);
    }

    // 析构函数：释放动态分配内存
	~String(){
        if (m_pstr) {
            delete[] m_pstr;
            m_pstr = nullptr;
        }
    }

    // 打印字符串内容
    void print(){
        cout << m_pstr << endl;
    }

    // 赋值运算符重载：String = String
	String &operator=(const String &rhs){
        if (this != &rhs) { // 防止自赋值
            delete[] m_pstr;
            m_pstr = new char[strlen(rhs.m_pstr) + 1];
            strcpy(m_pstr, rhs.m_pstr);
        }
        return *this;
    }

    // 赋值运算符重载：String = const char*
	String &operator=(const char *pstr){
        delete[] m_pstr;
        m_pstr = new char[strlen(pstr) + 1];
        strcpy(m_pstr, pstr);
        return *this;
    }

    // += 运算符重载：String += String
	String &operator+=(const String &rhs){
        char *newStr = new char[strlen(m_pstr) + strlen(rhs.m_pstr) + 1];
        strcpy(newStr, m_pstr);
        strcat(newStr, rhs.m_pstr);
        delete[] m_pstr;
        m_pstr = newStr;
        return *this;
    }

    // += 运算符重载：String += const char*
	String &operator+=(const char *pstr){
        char *newStr = new char[strlen(m_pstr) + strlen(pstr) + 1];
        strcpy(newStr, m_pstr);
        strcat(newStr, pstr);
        delete[] m_pstr;
        m_pstr = newStr;
        return *this;
    }

    // 下标访问运算符重载（可读写）
	char &operator[](size_t index){
        if (index >= strlen(m_pstr)) {
            cout << "illegal index" << endl;
            static char nullChar = '\0';
            return nullChar;
        } else {
            return m_pstr[index];
        }
    }

    // 下标访问运算符重载（只读）
	const char &operator[](size_t index) const{
        if (index >= strlen(m_pstr)) {
            cout << "illegal index" << endl;
            static char nullChar = '\0';
            return nullChar;
        } else {
            return m_pstr[index];
        }
    }

    // 获取字符串长度
	size_t size() const {
        return strlen(m_pstr);
    }

    // 返回 C 风格字符串指针
    const char* c_str() const {
        return m_pstr;
    }

    // 关系运算符重载为友元函数
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);

    // 流插入/提取运算符重载为友元函数
	friend ostream &operator<<(ostream &os, const String &s);
	friend istream &operator>>(istream &is, String &s);

private:
	char *m_pstr; // 字符串数据指针
};

// + 运算符重载：String + String
String operator+(const String &lhs, const String &rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

// + 运算符重载：String + const char*
String operator+(const String &lhs, const char *pstr){
    String tmp(lhs);
    tmp += pstr;
    return tmp;
}

// + 运算符重载：const char* + String
String operator+(const char *pstr, const String &rhs){
    String tmp(pstr);
    tmp += rhs;
    return tmp;
}

// == 运算符重载
bool operator==(const String &lhs, const String &rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

// != 运算符重载
bool operator!=(const String &lhs, const String &rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

// < 运算符重载（按字典序）
bool operator<(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

// > 运算符重载
bool operator>(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

// <= 运算符重载
bool operator<=(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

// >= 运算符重载
bool operator>=(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

// 输出运算符重载（打印字符串）
ostream &operator<<(ostream &os, const String &s){
    os << s.m_pstr;
    return os;
}

// 输入运算符重载（从输入流读取字符串）
istream &operator>>(istream &is, String &s){
    char buffer[1024]; // 临时缓冲区
    is >> buffer;      // 读取一个单词
    s = buffer;        // 调用重载的赋值运算符
    return is;
}

// 主函数：测试部分功能
int main()
{
    // 测试：构造和 print
    // String s1 = "Hello";
    // s1.print();

    // 测试：拷贝构造函数
    // String s1 = "World";
    // String s2 = s1;
    // s2.print();

    // 测试：+= 运算符
    // String s1 = "Hello";
    // String s2 = "World";
    // s1 += s2;
    // s1.print();

    // 测试：下标访问越界
    // String s1 = "Hello";
    // s1.print();
    // cout << s1[30] << endl;

    // 测试：比较运算符
    /*
    String s1("apple");
    String s2("apple");
    String s3("banana");
    String s4("Apple");
    String s5("applepie");
    String s6("app");

    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 != s3: " << (s1 != s3) << endl;
    cout << "s1 <  s3: " << (s1 <  s3) << endl;
    cout << "s1 >  s3: " << (s1 >  s3) << endl;
    cout << "s1 <= s2: " << (s1 <= s2) << endl;
    cout << "s1 >= s2: " << (s1 >= s2) << endl;
    cout << "s4 <  s1: " << (s4 <  s1) << endl;
    cout << "s5 >  s1: " << (s5 >  s1) << endl;
    cout << "s6 <  s1: " << (s6 <  s1) << endl;
    cout << "s6 >= s1: " << (s6 >= s1) << endl;
    */

    // 测试：流输入输出
    /*
    String s;
    cin >> s;
    cout << s << endl;
    */

    // 测试：String + String
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    s3.print(); // 输出 HelloWorld

    return 0;
}
