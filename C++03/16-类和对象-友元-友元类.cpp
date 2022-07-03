#include<iostream>
using namespace std;
/*
类做友元
*/
class Building; //先声明类
class GoodGay
{
public:
    GoodGay();
    void visit();
public:
    Building * b;
};


class Building
{
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class GoodGay;
    
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
    cout<<"好基友类正在访问："<<this->b->m_SittingRoom<<endl;
    cout<<"好基友类正在访问："<<this->b->m_BedRoom<<endl;
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