#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Employee: public Worker
{
public:
    //构造函数
    Employee(int ID, string name, int deptID);

    //显示职工信息的成员函数声明，父类是虚函数所以子类也是虚函数，此处的virtual关键字可加可不加。
    virtual void showInfo();

    //获取岗位名称
    virtual string getDeptName();
};