#include<iostream>
using namespace std;
/*
若类和结构体所有数据成员均为public型，可采取如下带花括号形式进行初始化。和结构体初始化方法相同
Person p = {"张三"  , 18};
未指定值的数据成员编译器会自动初始化为默认值

若数据成员有private或protected型，或是提供了构造函数，必须使用构造函数来进行初始化。
*/

#define PI 3.14 //注意，这种宏常量声明方式不需要在最后添加分号;
// const double PI2 = 3.14;

// 设计一个圆类，求圆的周长
class Circle
{
//访问权限
public:
    // 属性
    int m_r;
    // 行为
    double calculateZC(){
        return 2 * PI * m_r;
    }
};


int main(){

    // 创建圆对象，即实例化
    Circle c;
    c.m_r = 10;
    cout<<"周长为："<<c.calculateZC()<<endl;

    system("pause");
    return 0;
}