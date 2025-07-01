#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

class String {
public:
    String(const char * pstr){
        _size = strlen(pstr);
        if(_size < sizeof(_buffer._local)){
            strcpy(_buffer._local,pstr);
            _capacity = sizeof(_buffer._local);
        }else{
            _buffer._pointer = new char[_size + 1];
            strcpy(_buffer._pointer,pstr);
            _capacity = _size + 1;
        }
    }
    ~String();
    char & operator[](size_t idx){
        if(_size < sizeof(_buffer._local)){
            return _buffer._local[idx];
        }else{
            return _buffer._pointer[idx];
        }
    }

    friend
    ostream & operator<<(ostream & os,const String & rhs);
private:
	union Buffer{
		char * _pointer;
		char _local[16];
	};
	
	size_t _size;
	size_t _capacity;
    Buffer _buffer;
};

String::~String(){
    cout << "~String()" << endl;
    if (_size >= sizeof(_buffer._local)) {
        delete[] _buffer._pointer;
    }
}
ostream & operator<<(ostream & os,const String & rhs){
    if(rhs._size < sizeof(rhs._buffer._local)){
        os << rhs._buffer._local;
    }else{
        os << rhs._buffer._pointer;
    }
    return os;
}

void test0(){
    String str1("hello");
    String str2("hello,world!!!!!");
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    str1[0] = 'H';
    str2[0] = 'H';
    cout << "str1 (modified) = " << str1 << endl;
    cout << "str2 (modified) = " << str2 << endl;
}




int main()
{
    test0();
    return 0;
}

