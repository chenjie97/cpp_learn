#include<iostream>
using namespace std;
#include<string>
// 1、定义结构体
struct Student
{
    string name;
    int age;
    int score;
};


int main(){
    // 2、创建结构体数组，相当于数组的每一个元素存放的是结构体变量
    struct Student stuArray[3] = {
        {"张三",18,100},
        {"李四",19,99},
        {"王五",18,98}
    };
    
    // 3、给结构体数组中元素赋值
    stuArray[2].name = "赵六";
    
    // 4、遍历结构体数组
    int len = sizeof(stuArray)/sizeof(stuArray[0]);
    for (int i = 0; i < len; i++)
    {
        cout <<"姓名："<<stuArray[i].name<<" 年龄："<<stuArray[i].age<<" 分数："<<stuArray[i].score<<endl;
    }
    
    system("pause");
    return 0;
}