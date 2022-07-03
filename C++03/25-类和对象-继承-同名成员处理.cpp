#include<iostream>
using namespace std;

/*
问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？

* 访问子类同名成员   直接访问即可
* 访问父类同名成员   需要加作用域

在继承的时候会把父类的所有成员属性以及成员方法继承下来，但是遇到同名的变量或者函数会调用子类的成员，把父类的成员隐藏掉。
*/
class Base
{
public:
    int m_A;
    Base();

    void func(){
        cout<<"Base func函数调用"<<endl;
    }
    void func(int a){
        cout<<"Base func 有参函数调用"<<endl;
    }
    
};
Base::Base()
{
    m_A = 10;
}

class Son : public Base
{
public:
    int m_A;
    Son();
    void func(){
        cout<<"Son func函数调用"<<endl;
    }
};
Son::Son()
{
    m_A = 100;
}
void test01(){
    // 测试成员变量
    Son s;
    cout<<"子类的m_A="<<s.m_A<<endl;
    cout<<"父类的m_A="<<s.Base::m_A<<endl;
}

void test02(){
    // 测试成员函数
    Son s;
    s.func();
    s.Base::func();

    // s.func(10); 报错，无法调用父类的函数重载，这是因为遇到重名的函数会把父类的同名函数隐藏起来，不论函数的参数是什么形式。
    s.Base::func(10);
}


int main(){

    // test01();
    test02();
    system("pause");
    return 0;
}