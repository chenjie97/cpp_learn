#include<iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

// 使用地址传递：将函数中的形参改为指针，可以减少内存（因为指针只占用4 or 8个字节），并且不会产生新的副本出来
void printStudents(const struct Student * p){
    // 但是这个函数的功能仅仅是打印，不希望能够修改结构体的内容，所以加入const，防止函数内的误操作
    // p->age = 100; 会报错
    cout << "name:" << p->name << "\tage:" << p->age << "\tscore:" << p->score << endl;;
}


int main(){

    struct Student s1 = {"zhangsan",18,100};
    printStudents(&s1);


    system("pause");
    return 0;
}