/*
多态分为两类
* 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
* 动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：
* 静态多态的函数地址早绑定  -  编译阶段确定函数地址
* 动态多态的函数地址晚绑定  -  运行阶段确定函数地址
*/

#include<iostream>
using namespace std;


class Animal
{

public:
    //父类函数前面加virtual关键字
    virtual void speak(){
        cout<<"Animal is speaking!"<<endl;
    }
};

class Cat: public Animal
{
public:
    void speak(){
        cout<<"Cat is speaking!"<<endl;
    }
};

class Dog: public Animal
{
public:
    void speak(){
        cout<<"Dog is speaking!"<<endl;
    }
};

//父类引用可以指向子类对象，【继承关系的类之间可以进行类型转换，无需强制类型转化】
void doSpeak(Animal &animal){ // Animal & animal =  c;
    animal.speak();
}

void test01(){
    Animal a = Animal();
    Cat c = Cat();
    Dog d = Dog();
    doSpeak(a);
    doSpeak(c);
    doSpeak(d);
}



int main(){
    test01();
    system("pause");
    return 0;
}