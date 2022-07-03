#include<iostream>
using namespace std;
/*
首先要先复习一下静态成员：
    静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
    静态成员分为：
    *  静态成员变量
    *  所有对象共享同一份数据
    *  在编译阶段分配内存（生成EXE文件的时候）!! 而不是在exe文件双击运行阶段分配内存
    *  类内声明，类外初始化！！
    
    *  静态成员函数
    *  所有对象共享同一个函数
    *  静态成员函数只能访问静态成员变量


*/
class Base {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};

int Base::m_A = 100;

class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//同名成员属性
void test01()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	cout << "Son  下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	//通过类名访问
	cout << "通过类名访问： " << endl;
	cout << "Son  下 m_A = " << Son::m_A << endl;
    //第一个::代表通过类名的方式访问  第二个::代表访问父类作用域的成员
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
    cout << "Base 下 m_A = " << Base::m_A << endl;
}

//同名成员函数
void test02()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	s.func();
	s.Base::func();

	cout << "通过类名访问： " << endl;
	Son::func();
	Son::Base::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son::Base::func(100);
}

int main(){
    test01();
    // test02();
    system("pause");
    return 0;
}