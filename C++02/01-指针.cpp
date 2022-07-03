#include<iostream>
using namespace std;
/*
指针的作用：可以通过指针间接访问内存（指针可以保存一个地址）
可以简单理解为：指针就是某个变量的地址
指针可以访问内存，还能修改内存中变量的值（通过解引用）

指针也是一种数据类型:   所有指针类型 在32位操作系统下 占用4个字节，64位下占用8个字节。
常见的指针类型：
int *
float *
double *
char *
bool *
*/

int main(){
    
    int a = 10;

    // 1、定义指针
    int * p; //数据类型 * 指针变量名
    p = &a;  //
    // 2、使用指针
    *p = 1000; //*代表解引用，找到指针指向的内存的数据

    cout <<&p<<endl;
    cout <<a<<endl;
    cout <<*p<<endl;
    cout <<&p<<endl;


    system("pause");
    return 0;
}