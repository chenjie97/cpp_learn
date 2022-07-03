#include<iostream>
using namespace std;

/*
静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
静态成员分为：

*  静态成员变量
   *  所有对象共享同一份数据
   *  在编译阶段分配内存（生成EXE文件的时候）!! 而不是在exe文件双击运行阶段分配内存
   *  类内声明，类外初始化！！
   
*  静态成员函数
   *  所有对象共享同一个函数
   *  静态成员函数只能访问静态成员变量

在C++中，类内的成员变量和成员函数分开存储
只有非静态成员变量才属于类的对象上
空对象在内存中占1和字节

*/

class Person
{

public:
    int m_C = 66;
    static int m_A; //静态变量在类内声明，相当于函数的提前声明,这里是变量的提前声明。
    static void func(){
        // m_C = 1; 静态成员函数只能访问静态变量
        cout<<"静态成员函数调用，静态成员变量m_A="<< m_A <<endl;
    } 

private:
    // 静态变量也是有作用域的，私有
    static int m_B; //静态变量在类内声明
};
int Person::m_A = 100;//静态变量在类外初始化,作用域后紧跟变量名，这里是变量的正式初始化
int Person::m_B = 10;

void test01(){
    Person p1;
    //静态成员变量两种访问方式:1、通过对象；2、通过类名::
    cout<<p1.m_A<<endl;
    Person p2;
    p2.m_A = 200;
    // cout<<p.m_B<<endl; 会报错，私有属性不支持访问
    cout<<Person::m_A<<endl;
}

void test02(){
    //静态成员函数两种访问方式:1、通过对象；2、通过类名::
    Person p;
    p.func();

    Person::func();

}



int main(){
    // test01(); 测试静态成员变量
    test02(); // 测试静态成员函数 

    system("pause");
    return 0;
}