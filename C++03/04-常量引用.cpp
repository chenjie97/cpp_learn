#include<iostream>
using namespace std;

/*
引用本质上是一个 指针常量（数据类型 * const 指针名称 = 变量地址;）
那么，常量引用本质上就是一个常量指针常量（const 数据类型 * const 指针名称 = 变量地址;）也即是指针指向和指针指向的内容都不可以修改
常量引用代表 别名不能修改

使用场景：用来修饰形参防止误操作！

*/



void showValue(const int &a){
    // a = 100;// 这个函数仅仅只是个打印函数，不希望这个函数能够通过引用传递来修改,所以加const（常量引用）

    // 那么为什么不使用值传递呢？值传递的话修改形参就不会产生对实参的误操作了。
    // 那是因为值传递会开辟额外的内存空间，所以占内存
    cout<<"val = "<<a<<endl;
}


int main(){

    // int &b = 10; // 会出错，引用必须要引一块合法的内存空间

    // 加上const之后，编译器将代码修改为 int tmp = 10; const int &b = tmp;
    // const int &b = 10;//这句就不会报错
    // b = 20; // 加入const之后，变成只读，不支持修改

    int a = 10;
    showValue(a);



    system("pause");
    return 0;
}