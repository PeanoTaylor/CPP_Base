#include <iostream>
#include <cstring>
using namespace std;

class CharArray{
public:
    CharArray(const char *pstr)
    : m_pstr(new char[strlen(pstr) + 1]{})
    , m_capacity(strlen(pstr)){
        strcpy(m_pstr,pstr);
    }
    ~CharArray(){
        if(m_pstr){
            delete [] m_pstr;
            m_pstr = nullptr;
        }
    }

    char &operator[] (int index){
        // 判断是否越界
        if(index < 0 || index >= m_capacity){
            cout << "index is illegal" << endl;
            static char nullChar = '\0';
            return nullChar;
        }else{
            return m_pstr[index];
        }
    }

    void print()
    {
        cout << m_pstr << endl;
    }
private:
    char *m_pstr;
    int m_capacity;
};

int main()
{
    CharArray str { "abcd" };
    str.print();
    str[0] = 'A';
    str.print();
    return 0;
}

