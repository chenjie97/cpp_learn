#include<iostream>
using namespace std;
/*
c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝

如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/

class Person
{
    friend void test01();
private:
    int * m_Age;
public:
    Person(int a);
    ~Person();


    //为了让赋值操作能够实现链式运算，所以返回值应该要返回Person的对象。
    Person& operator=(Person &p){//注意此时必须使用引用传递,如果使用值传递的话也同样会产生重复释放的问题,此时是形参p和实参p1重复释放

        // 应该先判断是否有属性在堆区，如果有，要先释放干净，然后再深拷贝
        if (this->m_Age != NULL)
        {
            delete this->m_Age;
            this->m_Age = NULL;
        }

        //编译器的默认赋值操作为值传递,仅仅是把p这个对象的m_Age指针的值，重新拷贝了一份，值传递。
        //程序运行结束之后释放内存时会出现，重复释放的错误。此时是实参p1的引用和实参p2重复释放。
        //this->m_Age = p.m_Age; //编译器的默认赋值操作为值传递,是浅拷贝。
        this->m_Age = new int(*p.m_Age); // 重复释放的解决办法就是利用深拷贝

        return *this;
    }

};

Person::Person(int a)
{
    m_Age = new int(a);// 在堆区开辟内存，需要程序员手动释放掉。释放内存的操作可以放在类的析构函数中。
}

Person::~Person()
{
    if (m_Age != NULL)
    {
        delete m_Age;
        m_Age = NULL;
    }
    
}

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    cout<<"p1的年龄="<< *p1.m_Age<<endl;
    cout<<"p2的年龄="<< *p2.m_Age<<endl;
    cout<<"p3的年龄="<< *p3.m_Age<<endl;
    p2 = p1;
    cout<<"经过赋值运算之后，p2的年龄="<< *p2.m_Age<<endl;
    p3 = p2 = p1;
    cout<<"经过赋值运算之后，p3的年龄="<< *p3.m_Age<<endl;
}


int main(){
    test01();
    system("pause");
    return 0;
}