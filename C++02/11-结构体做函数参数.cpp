#include<iostream>
#include<string>
using namespace std;
/*
结构体向函数中传递有两种方式：
1、值传递：形参的改变不会影响实参
2、地址传递
*/

struct student
{
    string name;
    int age;
    int score;
};

void printStudent1(struct student s){
    // 值传递
    cout <<"函数值传递打印前 姓名："<< s.name <<" 年龄："<< s.age <<" 分数："<< s.score <<endl;
    s.name = "李四";
    cout <<"函数值传递打印后 姓名："<< s.name <<" 年龄："<< s.age <<" 分数："<< s.score <<endl;
}

void printStudent2(struct student * p){ // 将函数中的形参改为指针，可以减少内存（因为指针只占用4 or 8个字节），并且不会产生新的副本出来
    // 地址传递
    cout <<"函数值传递打印前 姓名："<< p->name <<" 年龄："<< p->age <<" 分数："<< p->score <<endl;
    p->name = "李四";
    cout <<"函数值传递打印后 姓名："<< p->name <<" 年龄："<< p->age <<" 分数："<< p->score <<endl;
}


int main(){
    // 创建结构体变量
    struct student s = {"张三", 20, 85};
    cout <<"main函数中打印 姓名："<< s.name <<" 年龄："<< s.age <<" 分数："<< s.score <<endl;
    printStudent1(s);
    cout <<"main函数中打印 姓名："<< s.name <<" 年龄："<< s.age <<" 分数："<< s.score <<endl;
    cout << "*****" <<endl;
    printStudent2(&s);
    cout <<"main函数中打印 姓名："<< s.name <<" 年龄："<< s.age <<" 分数："<< s.score <<endl;


    system("pause");
    return 0;
}