#include<iostream>
using namespace std;
/*
类模板做函数参数的三种方式：
1. 指定传入的类型   --- 直接显示对象的数据类型 （代码可读性高，推荐使用！！）
2. 参数模板化       --- 将对象中的参数变为模板进行传递
3. 整个类模板化     --- 将这个对象类型 模板化进行传递
*/

template<class T1, class T2>
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(T1 name, T2 age);
    void showInfo();
};

template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showInfo(){
    cout<<"姓名："<<m_Name<<" 年龄："<<m_Age<<endl;
}

//1、指定传入的类型
void showPersonInfo01(Person<string, int> &p){
    p.showInfo();
}
void test01(){
    Person<string, int> p("孙悟空", 800);
    showPersonInfo01(p);
}

//2、参数模板化
template<class T1, class T2>
void showPersonInfo02(Person<T1, T2> &p){
    p.showInfo();
    cout<<"T1的类型："<<typeid(T1).name()<<endl;
    cout<<"T2的类型："<<typeid(T2).name()<<endl;
}
void test02(){
    Person<string, int> p("猪八戒", 900);
    showPersonInfo02(p);
}

//3、类模板化
template<class T>
void showPersonInfo03(T &p){
    p.showInfo();
    cout<<"T的类型："<<typeid(T).name()<<endl;
}
void test03(){
    Person<string, int> p("沙和尚", 999);
    showPersonInfo03(p);
}

int main(){
    // test01();
    // test02();
    test03();
    system("pause");
    return 0;
}