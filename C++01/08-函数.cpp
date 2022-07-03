#include<iostream>
using namespace std;
/*
    函数在值传递的时候，形参发生的改变并不会影响实参， 与python传递不可变类型一致。

    b = 0
    b = 1 
    python：先执行等号右边，即申请一块内存存放1,并b指向该内存的地址
    c++：变量赋予新值时，变量指向的地址不变。即在原本的内存空间上修改值

    python和C++在变量赋值时的区别：
    python：是地址传递 a = b 是将b存放的地址传递给a ，此时只有一份内存空间存放1这个值
    C++：是值传递  a = b 是将b对应的值（1）传递给a,即此时有两份内存空间存放1这个值


    python不允许程序员选择采用传值还是传引用。Python参数传递采用的肯定是“传对象引用”的方式。这种方式相当于传值和传引用的一种综合。
    如果函数收到的是一个可变对象（比如字典或者列表）的引用，就能修改对象的原始值－－相当于通过“传引用”来传递对象。
    如果函数收到的是一个不可变对象（比如数字、字符或者元组）的引用，就不能直接修改原始对象－－相当于通过“传值'来传递对象。
    
*/

//函数的声明，若函数是在main()之后定义的需要提前声明
// 声明可以有多次，但是定义只能有一次
void add(int num1,int num2);
void add(int num1,int num2);
void add(int num1,int num2);

int main(){
    int a = 10;
    int b = 20;
    cout<<"实参，值传递之前："<<endl;
    cout << a << "\t" << b << endl;
    add(a,b);
    cout<<"实参，值传递之后："<<endl;
    cout << a << "\t" << b << endl;
    
    system("pause");
    return 0;
}

void add(int num1,int num2){
    cout<<"形参，改变前："<<endl;
    cout << num1 << "\t" << num2 << endl;
    num1++;
    num2++;
    cout<<"形参，改变后："<<endl;
    cout << num1 << "\t" << num2 << endl;
}