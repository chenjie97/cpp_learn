/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**

虚析构和纯虚析构共性：
* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：
* 如果是纯虚析构，该类属于抽象类，无法实例化对象

*/
#include<iostream>
using namespace std;
class Animal
{
public:
    Animal();
    // 纯虚函数
    virtual void Speak() = 0;
    
    // 虚析构函数，如果没有虚析构函数的话，子类对象开辟在堆区的内存无法释放，出现内存泄漏的问题。
    // virtual ~Animal();

    // 纯虚析构函数
    virtual ~Animal() = 0;
};

Animal::Animal()
{
    cout<<"Animal 构造函数调用！"<<endl;
}

Animal::~Animal()
{
    cout<<"Animal 析构函数调用！"<<endl;
}

class Cat:public Animal
{
public:
    Cat(string name);

    virtual void Speak()
	{
		cout << *this->name <<  "小猫在说话!" << endl;
    }

    ~Cat();
    
    string * name;
};

Cat::Cat(string name)
{
    cout<<"Cat 构造函数调用！"<<endl;
    this->name = new string(name);
}

Cat::~Cat()
{
    cout<<"Cat 析构函数调用！"<<endl;
    if(this->name != NULL){
        delete this->name;
        this->name = NULL;
    }
}

void test01(){
    Animal * animal = new Cat("Tom");
     // 在多态的时候父类指针（引用）指向子类对象，会默认进行类型转换，如果没有虚函数的话，会调用父类的相关函数。
    animal->Speak();    
    delete animal;
}

int main(){

    test01();
    system("pause");
    return 0;
}