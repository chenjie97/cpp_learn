#include<iostream>
using namespace std;
/*
函数模板作用：建立一个通用函数，其函数“返回值类型”和“形参类型”可以不具体制定，用一个**虚拟的类型**来代表。

总结：
* 函数模板利用关键字 template
* 使用函数模板有两种方式：自动类型推导、显示指定类型
* 模板的目的是为了提高复用性，将类型参数化
*/

void swapInt(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void swapFloat(float &a, float &b){
    float tmp = a;
    a = b;
    b = tmp;
}

//函数模板
//typename关键字也可以替换为class
template<typename T> // 声明一个模板，并告知编译器：T是一个通用的数据类型。
void mySwap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

void test01(){
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    float c = 1.1;
    float d = 2.2;
    swapFloat(c, d);
    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;
}

void test02(){
    cout<<"使用函数模板："<<endl;
    int a = 10;
    int b = 20;
    //两种方式使用函数模板：
    //1、自动类型推导
    mySwap(a, b);  //编译器根据a，b的数据类型自动将T推导为int类型
    //2、显式指定类型
    // mySwap<int>(a, b); //主动告知编译器T的数据类型2为int
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    float c = 1.1;
    float d = 2.2;
    mySwap<float>(c, d); //2、显式指定类型
    // mySwap(c, d);  //1、自动类型推导
    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;
}


int main(){

    // test01();
    test02();
    system("pause");
    return 0;
}