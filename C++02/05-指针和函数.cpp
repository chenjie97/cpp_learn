#include <iostream>
using namespace std;
/*
python不允许程序员选择采用传值还是传引用。Python参数传递采用的肯定是“传对象引用”的方式。这种方式相当于传值和传引用的一种综合。
如果函数收到的是一个可变对象（比如字典或者列表）的引用，就能修改对象的原始值－－相当于通过“传引用”来传递对象。
如果函数收到的是一个不可变对象（比如数字、字符或者元组）的引用，就不能直接修改原始对象－－相当于通过“传值'来传递对象。
*/

void swap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout <<"swap01  a:"<<a<<" b:"<<b<<endl;
}

void swap02(int * p1, int * p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    // 1、值传递, 形参的改变不会改变实参的值
    int a = 10;
    int b = 20;
    swap01(a, b);
    cout <<"a:"<<a<<" b:"<<b<<endl;

    // 2、地址传递，可以改变实参的值
    swap02(&a, &b);
    cout <<"a:"<<a<<" b:"<<b<<endl;
    system("pause");
    return 0;
}