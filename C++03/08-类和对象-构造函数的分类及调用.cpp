#include<iostream>
using namespace std;

//构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造

/*
构造函数调用规则如下：
	1、如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
	2、如果用户定义拷贝构造函数，c++不会再提供其他构造函数
*/

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int a) {
		age = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
        // 参数使用常量引用，这是因为不希望在拷贝构造函数中对原来的对象进行修改。
		age = p.age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

//2、构造函数的调用
//调用无参构造函数（默认构造函数）
void test01() {
	Person p; //调用无参构造函数
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	//Person p2();
    //类似于void func();
}

//调用有参的构造函数
void test02() {

	//2.1  括号法，常用
	Person p1(10);//有参构造函数
    Person p2(p1);//拷贝构造函数

	

	//2.2 显式法
	Person p2 = Person(10); //有参构造函数
	Person p3 = Person(p2); //拷贝构造函数

	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构
    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	//Person(p4); 等价于 Person p4; 

	//2.3 隐式转换法
	Person p4 = 10; // Person p4 = Person(10); 有参构造
	Person p5 = p4; // Person p5 = Person(p4); 拷贝构造

	
}

int main() {

	test01();
	//test02();

	system("pause");

	return 0;
}