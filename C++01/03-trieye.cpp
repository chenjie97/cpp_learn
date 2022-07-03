#include<iostream>
using namespace std;

/*
三目运算符：
c = a > b ? a : b ;

python中也有类似三目运算符的东西：
c = a if a > b else b
*/

int main(){

    //三目运算符
    int a = 5;
    int b = 10;
    int c = 0;
    c = a > b ? a : b ;

    cout <<"c = "<< c <<endl;

    // 注意在C++中三目运算符得到的是一个变量 可以继续赋值
    a > b ? a : b = 100;
    cout << "a = "<<a<<endl;
    cout << "b = "<<b<<endl;
    
    system("pause");
    return 0;
}