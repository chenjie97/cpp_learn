#include<iostream>
using namespace std;
/*
注意事项：
1、自动类型推导，必须推导出一致的数据类型T,才可以使用
2、（不论是 自动推导 还是 显式指定）模板必须要确定出T的数据类型，才可以使用
*/

template<class T>
void mySwap(T &a, T&b){
    T tmp = a;
    a = b;
    b = a;
}

void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a, b);//正确！此时编译器能推导出T是int类型
    // mySwap(a, c);//错误！编译器根据a推导T为int，但是根据c推导出T为char,冲突了！！
}

template<class T>
void fun(){
    cout<<"fun()被调用！"<<endl;
}

void test02(){
    // fun();//错误！编译器无法推测出T的具体类型是什么。
    fun<int>();//正确！显式的告诉编译器T是int类型。因为fun()并没有用到T，所以指定的类型随意即可。
}


int main(){


    system("pause");
    return 0;
}