#include<iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(string str, int age);

    //利用成员函数实现==运算符的重载
    bool operator==(Person &p){
        bool ret = false;
        if (name == p.name && age == p.age)
        {
            bool ret = true;
        }
        return ret;
    }
};

Person::Person(string str, int age)
{
    this->name = str;
    this->age = age;
}

void test01(){
    Person p1("Tom", 18);
    Person p2("Jerry",16);

    if(p1 == p2){
        cout<<"p1和p2相等！"<<endl;
    }
    else
    {
        cout<<"p1和p2不相等！"<<endl;
    }
    

}


int main(){
    test01();
    system("pause");
    return 0;
}

    