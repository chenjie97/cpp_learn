#include<iostream>
using namespace std;

/*
总结：继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
"父亲生儿子，但是白发人送黑发人！"
*/

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
    // 子类占16个字节
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();
	system("pause");
	return 0;
}