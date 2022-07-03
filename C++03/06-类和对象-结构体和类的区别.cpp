#include<iostream>
using namespace std;
/*
在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**

区别：

* struct 默认权限为公共
* class   默认权限为私有

头文件源文件分离：
https://www.bilibili.com/video/BV1et411b73Z?p=105&spm_id_from=333.1007.top_right_bar_window_history.content.click
*/
class C1
{
    int m_A = 10;
};

struct C2
{
    int m_A = 100;
};


int main(){
	C1 c1;
	// c1.m_A = 10; //错误，访问权限是私有

	C2 c2;
	c2.m_A = 10; //正确，访问权限是公共
    
    system("pause");
    return 0;
}