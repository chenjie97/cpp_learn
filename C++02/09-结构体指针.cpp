#include<iostream>
#include<string>
using namespace std;
// 通过指针访问结构体中的成员  操作符： ->
// 区分结构体和结构体变量， 类似于 类和对象的关系

// 1、定义结构体
struct Student{
    // 成员列表
    string name;
    int age;
    int score;
};


int main(){
    // 2、创建一个结构体变量,struct可以省略
    struct Student s1 = {"张三", 18, 100};
    // 3、通过指针指向结构体变量,struct可以省略。注意 struct也是需要取址符&的
    struct Student * p =  &s1;
    // 4、通过指针访问结构体变量的数据   指针是利用操作符 -> 来访问结构体变量的属性的
    cout <<"姓名： "<< p -> name <<" 年龄： "<<p -> age<<" 分数： "<<p->score<<endl;
    //注意：p->name 等价于 (*p).name
    


    system("pause");
    return 0;
}