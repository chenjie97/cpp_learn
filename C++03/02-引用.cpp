#include<iostream>
using namespace std;

/*
引用:
    C++推荐使用 引用 技术

    作用：给变量起一个别名

    基本语法：数据类型 &别名 = 原名;

    注意事项:
        (1)引用必须初始化；int &b;//只声明，不初始化会报错！
        (2)引用在初始化之后，不可以改变。 

    
    本质：是指针常量（指针指向不能变，但是指针指向的内容可以变）
*/

int main(){

    int a = 10;
    int c = 20;

    int &b = a;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;

    b = 100;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;

    b = c; //引用不支持修改，这里是赋值操作，将c的值赋给b
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;

    system("pause");
    return 0;
}