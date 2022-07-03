#include<iostream>
using namespace std;
#include<stack>
/*
栈：先进后出的数据结构

栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
遍历指的是非质变的算法，不允许修改容器的值。

栈中进入数据称为  --- **入栈**  `push`
栈中弹出数据称为  --- **出栈**  `pop`
*/

//stack的初始化方式
void test01(){
/*
* `stack<T> stk;`                       //stack采用模板类实现， stack对象的默认构造形式
* `stack(const stack &stk);`            //拷贝构造函数
*/
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    stack<int> s2(s);
}

//stack的赋值操作
void test02(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    stack<int> s2;
    s2 = s1;
}

//stack的入栈和出栈
void test03(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.pop();
    s1.top();
}

//stack的大小
void test04(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.empty();
    s1.size();
}

int main(){

    system("pause");
    return 0;
}