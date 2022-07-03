#include<iostream>
using namespace std;

/*
当类模板碰到继承时，需要注意一下几点：

* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型, 如果不指定，编译器无法给子类分配内存
* 如果想灵活指定出父类中T的类型，子类也需变为类模板
*/

template<class T>
class Base
{

public:
    T m_Member;
};

// class Son: public Base//报错！子类在声明的时候，要指定出父类中T的类型
class Son: public Base<int>
{
};
void test01(){
    Son s; //子类能够正常实例化
}

//如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1, class T2>
class Son2: public Base<T1>
{
public:
    T2 obj;
    Son2(){
        cout<<"T1的数据类型为"<<typeid(T1).name()<<endl;
        cout<<"T2的数据类型为"<<typeid(T2).name()<<endl;
    }
};
void test02(){
    Son2<int, char> s;
}


int main(){

    test02();
    system("pause");
    return 0;
}