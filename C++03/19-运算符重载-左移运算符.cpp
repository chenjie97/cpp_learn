#include<iostream>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream &cout, Person &p);   
private:
    int m_A;
    int m_B;
public:
    Person(int a, int b);
    //1、利用成员函数实现左移运算符重载,但这样实现函数调用是： p.operator<<(cout) <=等价于=> p<<cout
    //无法实现cout在左侧 
    // void operator<<(ostream &cout){}
};

Person::Person(int a, int b)
{
    m_A = a;
    m_B = b;
}

//2、利用全局函数实现左移运算符重载
// 因为要实现左移运算符的链式运算，所以函数要返回一个ostream类型的对象
// 函数的参数中ostream &cout只能以引用的形式传进来，不能值传递。因为要保证全局只有一个。
ostream& operator<<(ostream &cout, Person &p){
    cout<<"m_A="<<p.m_A<<" m_B="<<p.m_B;
    return cout;
}

void test01(){
    Person p(10,10);
    cout<<p<<" hello"<<endl;
}


int main(){
    test01();
    system("pause");
    return 0;
}