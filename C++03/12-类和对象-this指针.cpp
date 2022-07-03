#include<iostream>
using namespace std;

/*
c++提供特殊的对象指针，this指针。this指针指向被调用的成员函数所属的对象。
this指针的用途：
*  当形参和成员变量同名时，可用this指针来区分
*  在类的 非静态成员函数 中返回对象本身，可使用return *this   //注意：此时是引用返回（需要加&符号）

本质：this指针本质上是一个指针常量。指针的指向不能修改。
*/

class Person
{
public:
    int age;
    Person(int age);

    //注意：此时是引用返回（需要加&符号），如果没有这个&就变成值返回，会拷贝一份和this指向的对象一样的数据返回。和原来的this指向的对象就无关了
    Person& PersonAddPerson(Person p);

};

Person::Person(int age)
{
    this->age = age;//用途1：解决变量命名冲突问题。
}

Person& Person::PersonAddPerson(Person p) //注意作用域Person::要放在函数名前面，返回值类型的后面
{
    this->age += p.age;
    //返回对象本身
    return *this;
}

void test01(){
    Person p(18);
    cout<<"p的年龄="<<p.age<<endl;
}
void test02()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}


int main(){
    // test01();
    test02();
    system("pause");
    return 0;
}