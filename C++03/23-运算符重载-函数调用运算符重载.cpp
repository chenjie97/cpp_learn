#include<iostream>
using namespace std;

class Print
{
public:
    void operator()(string text){
        cout<<text<<endl;
    }

};

void test01(){
    Print print;
    print("hello world!");//由于使用起来非常像一个函数，所以被称作仿函数
}



int main(){
    test01();
    system("pause");
    return 0;
}