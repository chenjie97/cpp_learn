#include<iostream>
using namespace std;

/*
深拷贝与浅拷贝：
    浅拷贝：简单的赋值拷贝操作（带来的问题是：堆区中的空间被重复释放==>利用深拷贝解决）
    深拷贝：在堆区重新申请空间，进行拷贝操作(利用new操作符在堆区申请空间)
*/
class Person
{
public:
    int m_Age;
    int * m_Height;
public:
    Person();
    Person(int age, int height);
    Person(const Person &p);
    ~Person();
};

Person::Person()
{
    cout<<"默认构造函数调用"<<endl;
}

Person::Person(int age, int height)
{
    m_Age = age;
    m_Height = new int(height); //在利用new在堆区开辟空间，返回的是空间的地址，所以用指针变量接收。
    cout<<"有参构造函数调用"<<endl;
}
Person::Person(const Person &p){
    m_Age = p.m_Age;
    // m_Height = p.m_Height;//默认的拷贝构造参数就是这行代码，简单的浅拷贝操作
    m_Height = new int(*p.m_Height);//深拷贝，重新在堆区申请空间
}

Person::~Person()
{   
    //析构函数的用处之一就是释放开辟在堆区的空间
    if (m_Height != NULL)
    {
        delete m_Height; //在堆区开辟的空间需要程序员手动释放
        m_Height = NULL; //将指针变成空指针，避免野指针的情况
    }
    
    cout<<"析构函数调用"<<endl;
}

void test01(){
    Person p1(18, 160);
    cout<<"p1的年龄为："<<p1.m_Age<<"身高："<<*p1.m_Height<<endl;

    Person p2(p1);
    cout<<"p2的年龄为："<<p2.m_Age<<"身高："<<*p2.m_Height<<endl;
}


int main(){

    test01();

    system("pause");
    return 0;
}