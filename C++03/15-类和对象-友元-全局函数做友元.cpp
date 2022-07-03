#include<iostream>
using namespace std;

/*
在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为  ==friend==

友元的三种实现
* 全局函数做友元
* 类做友元
* 成员函数做友元

*/
class Building
{
    //告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
    friend void goodGay(Building &b);
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom; // 私有属性

};

Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

// 全局函数
void goodGay(Building &b){
    cout<<"好基友全局函数正在访问："<<b.m_SittingRoom<<endl;
    cout<<"好基友全局函数正在访问："<<b.m_BedRoom<<endl;
}




int main(){
    Building b;
    goodGay(b);
    system("pause");
    return 0;
}