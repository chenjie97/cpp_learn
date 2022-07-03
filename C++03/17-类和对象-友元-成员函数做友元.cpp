#include<iostream>
using namespace std;

class Building; //先声明类
class GoodGay
{
public:
    GoodGay();
    void visit();
    void visit2();
public:
    Building * b;
};


class Building
{
    //告诉编译器  GoodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void GoodGay::visit();
    
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
GoodGay::GoodGay()
{
	b = new Building;//在堆区创建
}
void GoodGay::visit(){
    cout<<"visit正在访问："<<this->b->m_SittingRoom<<endl;
    cout<<"visit正在访问："<<this->b->m_BedRoom<<endl;
}
void GoodGay::visit2(){
    cout<<"visit2正在访问："<<this->b->m_SittingRoom<<endl;
    // cout<<"visit2正在访问："<<this->b->m_BedRoom<<endl; //不能访问私有属性
}


void test01(){
    GoodGay gg;
    gg.visit();
}

int main(){
    test01();
    system("pause");
    return 0;
}