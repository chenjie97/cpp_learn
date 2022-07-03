#include<iostream>
using namespace std;
/*
模板的局限性：
模板并不是万能的，**特定的类型**需要提供**具体化的模板**来特殊实现
*/

class Person
{
private:
    
public:
    string m_Name;
    int m_Age;
    Person(string name, int age);
};
Person::Person(string name, int age){
    m_Name = name;
    m_Age = age;
}


//对比两个数据是否相等的函数
template<class T>
bool myCompare(T &a, T &b){
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//具体化，以template<>开头，并通过名称来指出类型
//具体化模板优先于常规模板
template<> bool myCompare(Person &a, Person &b){
    if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void test01(){

    int a = 10;
    int b = 20;
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout<<"a==b"<<endl;
    }
    else
    {
        cout<<"a!=b"<<endl;
    }
    
    
}

void test02(){
    //自定义数据类型的对比
    Person p1("tom", 18);
    Person p2("jerry", 16);
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout<<"p1等于p2"<<endl;
    }
    else
    {
        cout<<"p1不等于p2"<<endl;
    }
}

int main(){

    test01();
    system("pause");
    return 0;
}