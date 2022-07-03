/*
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
因此可以将父类的虚函数改为**纯虚函数**

纯虚函数语法：`virtual 返回值类型 函数名 （参数列表）= 0 ;`

当类中有了纯虚函数，这个类也称为==抽象类==

**抽象类特点**：
 * 无法实例化对象
 * 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/
#include<iostream>
using namespace std;


class Base
{
public:
	//纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func() 
	{
		cout << "func调用" << endl;
	};
};

void test01()
{
	Base * base = NULL; //虽然抽象类无法实例化对象,但可以创建对应类型的指针变量。
	//base = new Base; // 错误，抽象类无法实例化对象(错在：new Base)

	// Base b; // 错误，抽象类无法实例化对象(错在：Base b)

	base = new Son;
	base->func();
	delete base;//记得销毁
}

int main() {

	test01();
	system("pause");
	return 0;
}