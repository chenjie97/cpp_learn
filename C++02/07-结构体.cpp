#include<iostream>
#include<string>
using namespace std;

/*
结构体：用户自定义的数据类型，允许用户存储不同的数据类型，即不同数据类型的集合叫做结构体

struct是class的前身：所有成员公开、没有构造函数和析构函数。
不用多态所以效率会高（多态会拖慢运行速度）
*/

// 1、创建自定义学生数据类型
struct Student
{
    // 成员列表
    string name;
    int age;
    int score;
}s3; //顺带创建一个结构体变量



int main(){
    // 2、通过学生类型创建具体的学生 三种方式
    // 结构体变量创建的时候struct关键字可以省略,但是在结构体定义的时候struct关键字不可以省略.
    // 第一种：
    struct Student s1;
    // 给s1的属性赋值
    s1.name = "张三";
    s1.age = 18;
    s1.score = 99;
    cout <<"s1 姓名："<<s1.name<<" 年龄："<<s1.age<<" 分数："<<s1.score<<endl;

    // 第二种：
    struct Student s2 = {"jay",25,100};
    cout <<"s2 姓名："<<s2.name<<" 年龄："<<s2.age<<" 分数："<<s2.score<<endl;
    // 第三种：在定义结构体的时候顺带创建一个结构体变量。如第19行。不建议使用。
    s3.name = "李四";
    s3.age = 25;
    s3.score = 89;
    cout <<"s3 姓名："<<s3.name<<" 年龄："<<s3.age<<" 分数："<<s3.score<<endl;

    system("pause");
    return 0;
}