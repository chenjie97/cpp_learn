#include<iostream>
using namespace std;

/*
空指针是可以调用成员函数的，但是也要注意有没有用到this指针，如果用到this指针的话会报错

如果用到this指针，需要加以判断保证代码的健壮性
*/

class Person
{
public:
    int m_Age;
    void showClassName(){
        cout<<"调用Person类"<<endl;
    }
    void showPersonAge(){
        //加入判断，保证鲁棒性
        if (this == NULL)
        {
            return;
        }
        
        cout<<"age= "<<m_Age<<endl;//本质上是调用了 this->m_Age
    }
};



void test01(){
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}


int main(){
    test01();
    system("pause");
    return 0;
}