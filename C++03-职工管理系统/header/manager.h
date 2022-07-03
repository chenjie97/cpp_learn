#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Manager: public Worker
{
public:

    Manager(int ID, string name, int deptID);

    //显示职工信息
    virtual void showInfo();

    //获取岗位名称
    virtual string getDeptName();
};