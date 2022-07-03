#include<iostream>
using namespace std;

/*
总结： 前置递增返回引用，后置递增返回值
*/

class MyInteger
{
    friend ostream& operator<<(ostream &cout, MyInteger num);
private:
    int m_Num;
public:
    MyInteger();
    MyInteger(int a);
    //前置递增重载,为了实现链式运算，所以要返回本身,用引用接收返回值
    MyInteger& operator++(){
        m_Num++;
        return *this;
    }

    //后置递增重载
    //注意返回值不同并不能作为函数重载的条件，所以需要用到占位参数来实现后置++。
    //因为引用不能用来返回局部变量，因为局部变量存储在栈区，函数调用结束之后就会被释放。引用就会出错。
    //由于返回的是值传递，所以并不能用来实现连式运算
    MyInteger operator++(int){
        //因为是后置运算，所以首先记录当前值
        MyInteger tmp = *this;
        m_Num++;
        return tmp;
    }
};

MyInteger::MyInteger()
{
    m_Num = 0;
}
MyInteger::MyInteger(int a)
{
    m_Num = a;
}
// 后置++返回一个值，若重载 << 运算符参数为引用，匿名对象无法初始化引用
// 匿名对象不能作为引用传进去。 匿名对象只存在于构造该对象的那行代码,离开构造匿名对象的哪行代码后立即调用析构函数。
// MyInteger &b = MyInteger(); 这句代码会报错。
ostream& operator<<(ostream &cout, MyInteger myint){
    cout<<myint.m_Num;
    return cout;
}

void test01(){
    MyInteger myint;
    cout<<myint<<endl;
}
void test02(){
    MyInteger myint;
    cout<<++(++myint)<<endl;
    cout<<myint<<endl;
}
void test03(){
    MyInteger myint;
    cout<<myint++<<endl;
    cout<<myint<<endl;
}

int main(){
    // test01();
    // test02();
    test03();
    system("pause");
    return 0;
}