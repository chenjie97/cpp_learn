#include<iostream>
using namespace std;

/*
常函数和常对象：

**常函数：**
* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**
* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数
*/
class Person{
public:
    // 常函数
    void showPerson() const
    //成员函数之后的const修饰的是this指针
    {   
        // m_A = 100; 会报错，常函数内不可以修改成员属性
        // this->m_A = 100; //本质：this指针本质上是一个指针常量。指针的指向不能修改。等价于 Person * const this;
        // 在函数后面加上const变成常函数本质是：const Person * const this; 常量指针常量，this指针的指向和值都不能修改

        this->m_B = 100; // 成员属性声明时加关键字mutable后，在常函数中依然可以修改
    }
    void func(){
        m_A = 100;
    }
    int m_A;
    mutable int m_B;

};

void test01(){
    Person p;
    p.showPerson();
}

void test02(){
    // 常对象
    const Person p{};
    // p.m_A = 100; 常对象不能访问成员变量
    p.m_B = 100;

    // 常对象只能调用常函数
    p.showPerson(); 
    // p.func(); 会报错，因为常函数不能调用普通成员函数，普通成员函数可以修改成员属性
}




int main(){
    // test01();
    test02();
    system("pause");
    return 0;
}