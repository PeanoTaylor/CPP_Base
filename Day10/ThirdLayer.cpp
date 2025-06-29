#include <iostream>
using namespace std;

class Data {
public:
    Data(int d = 0) : _data(d) {
        cout << "Data()" << endl;
    }
    ~Data() {
        cout << "~Data()" << endl;
    }

    int getData() const {
        return _data;
    }

private:
    int _data;
};

class MiddleLayer {
public:
    MiddleLayer(Data* p) : _pdata(p) {
        cout << "MiddleLayer()" << endl;
    }
    ~MiddleLayer() {
        cout << "~MiddleLayer()" << endl;
        delete _pdata;
        _pdata = nullptr;
    }

    Data* operator->() {
        return _pdata;
    }

private:
    Data* _pdata;
};

class ThirdLayer {
public:
    ThirdLayer(MiddleLayer* pm) : _pml(pm) {
        cout << "ThirdLayer()" << endl;
    }
    ~ThirdLayer() {
        cout << "~ThirdLayer()" << endl;
        delete _pml;
        _pml = nullptr;
    }

    Data* operator->() {
        return _pml->operator->();  // 转发调用
    }

private:
    MiddleLayer* _pml;
};


int main() {
    ThirdLayer* p3 = new ThirdLayer(new MiddleLayer(new Data(42)));

    cout << "调用 getData(): " << p3->operator->()->getData() << endl;

    delete p3; // 自动释放 ThirdLayer -> MiddleLayer -> Data

    return 0;
}
