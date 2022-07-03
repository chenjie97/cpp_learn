#include<iostream>
using namespace std;
/*
运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

运算符重载本质上是函数重载。

总结1：对于内置的数据类型【整型、浮点型等】的表达式的的运算符是不可能改变的
总结2：不要滥用运算符重载
*/

class Person
{
public:
    int m_A;
    int m_B;
// public:
//     // 1、通过成员函数来实现加法重载
//     Person operator+(Person &p){ //因为要返回一个新的Person对象，所以返回值类型不需要加引用（&）符号
//         Person tmp;
//         tmp.m_A = this->m_A + p.m_A;
//         tmp.m_B = this->m_B + p.m_B;
//         return tmp;
//     }
public:
    // 1、通过成员函数来实现加法重载,实现对象和整型的加法运算
    Person& operator+(int a){
        this->m_A = this->m_A + a;
        this->m_B = this->m_B + a;
        return *this;
    }
};
//2、通过全局函数实现加法运算符重载
Person operator+(Person &p1, Person &p2){
    Person tmp;
    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp;
}

void test01(){
    Person p1;
    p1.m_A = 1;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 2;
    p2.m_B = 20;

    Person p3 = p1 + p2;
    cout<<"p3.m_A="<<p3.m_A<<endl;
    cout<<"p3.m_B="<<p3.m_B<<endl;
    p3 + 10;
    cout<<"p3.m_A="<<p3.m_A<<endl;
    cout<<"p3.m_B="<<p3.m_B<<endl;
}




int main(){
    test01();
    system("pause");
    return 0;
}