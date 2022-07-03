#include<iostream>
#include<string>
using namespace std;

/*
    注意：在结构体嵌套的时候，包含在里面的结构体需要提前声明。
*/

struct Student
{
    string name;
    int age;
    int score;
};



struct Teacher
{
    int id;
    string name;
    struct Student stu;
};


int main(){
    Student s = {"张同学", 18, 100};
    Teacher t = {1000, "王老师", s};

    cout <<"老师姓名： "<< t.name <<" 学生姓名： "<<t.stu.name<<endl;


    
    system("pause");
    return 0;
}