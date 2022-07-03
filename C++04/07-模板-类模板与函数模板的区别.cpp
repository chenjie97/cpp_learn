#include<iostream>
using namespace std;

/*
类模板：建立一个通用类，类中的成员数据类型可以不具体指定，用一个虚拟的类型来代表

类模板与函数模板区别主要有两点：
1. 类模板没有 自动类型推导 的使用方式
2. 类模板在模板参数列表中可以有默认参数
*/

//类模板可以有默认参数
template<class NameType, class AgeType = int>
class Person
{

public:
    NameType m_Name;
    AgeType m_Age;
    Person(NameType name, AgeType age);
    void showPerson(){
        cout<<"name = "<<this->m_Name
            <<"\tage = "<<this->m_Age<<endl;

    }
};

//类内函数 类外实现的方式
template<class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
    this->m_Name = name;
    this->m_Age = age;
}

void test01(){
    // Person p("tom",18); //报错！类模板不支持自动类型推导
    //类模板只能用显式指定类型
    Person<string, int> p("tom", 18);
    p.showPerson();
}

void test02(){
    Person<string> p("jerry", 16);
    p.showPerson();
}

int main(){
    // test01();
    test02();
    system("pause");
    return 0;
}