#include<iostream>
using namespace std;

/*
引用做函数参数：
    作用：函数传参时，可以利用 引用 让形参改变实参
*/

// 交换函数
// 1、值传递
void swap01(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
// 2、地址传递（使用指针）
void swap02(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 3、引用传递（通过引用）
void swap03(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){

    int a = 10;
    int b = 20;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    swap01(a,b);//值传递，形参并不会改变实参
    cout<<"swap01 a = "<<a<<endl;
    cout<<"swap01 b = "<<b<<endl;

    swap02(&a,&b);//地址传递，形参会改变实参
    cout<<"swap02 a = "<<a<<endl;
    cout<<"swap02 b = "<<b<<endl;

    swap03(a,b);//引用传递，形参会改变实参
    cout<<"swap03 a = "<<a<<endl;
    cout<<"swap03 b = "<<b<<endl;


    system("pause");
    return 0;
}