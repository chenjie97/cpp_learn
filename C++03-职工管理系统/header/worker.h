#pragma once
#include<iostream>
using namespace std;

//定义Worker抽象类，使用纯虚函数。
//因为是抽象类不需要实现，所以不需要写worker类的源文件了
class Worker 
{

public:
    //显示职工信息
    virtual void showInfo() = 0;

    //获取岗位名称
    virtual string getDeptName() = 0;

    int m_ID;//职工编号
    string m_Name;//职工姓名
    int m_DeptID;
};