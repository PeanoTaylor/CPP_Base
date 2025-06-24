#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
	// 无参构造函数
	String(): _pstr(nullptr){}
	// 带参构造函数
	String(const char *pstr){
        if(pstr){
            _pstr = new char[strlen(pstr) + 1];
            strcpy(_pstr,pstr);
        }else{
            _pstr = nullptr;
        }
    }
    // 复制构造函数
	String(const String &rhs){
        if(rhs._pstr){
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr,rhs._pstr);
		}else{
			_pstr = nullptr;
		}
    }
	String &operator=(const String &rhs){
		if(this == &rhs) return *this; // 防止自赋值
		
		delete [] _pstr;

		if(rhs._pstr){
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr,rhs._pstr);
		}else{
			_pstr = nullptr;
		}

		return *this;
	}
	~String(){
        delete [] _pstr;
    }
	void print(){
        cout << "_pstr: " << (_pstr ? _pstr : "null") << endl;
    }
    size_t length() const;
    const char * c_str() const;

private:
	char * _pstr;
};

int main()
{
	String str1;
	str1.print();
	

	String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
	
	return 0;
}