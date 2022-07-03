#include<iostream>
using namespace std;

// 通常情况下，类的声明放在头文件中，函数实现放在源文件中
class Person
{

public:
    Person(); // 构造函数声明
    ~Person(); // 析构函数声明
};

// 构造函数实现
Person::Person()
{
    cout<<"Person 构造函数调用"<<endl;
}
// 析构函数实现
Person::~Person()
{
    cout<<"Person 析构函数调用"<<endl;
}

void test01(){
    Person p;
}


int main(){

    test01();
    system("pause");
    return 0;
}