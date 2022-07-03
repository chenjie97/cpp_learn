#pragma once // 避免同一个头文件被包含多次
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>

#define FILENAME "empFile.txt"


/*
头文件与源文件的区别:
头文件是“.h”文件,提供接口;  源文件是“.cpp”文件,提供实现。
编译器规定源文件必须包含函数入口,即main函数;
而头文件不得包含函数入口,头文件不可以单独编译成一个程序,仅仅包含程序片段或者定义常,变量。”
*/

class WorkerManager
{
private:
    /* data */
public:
    WorkerManager();

    //展示菜单
    void showMenu();

    //退出系统
    void exitSystem();

    //添加职工
    void addEmp();

    //保存文件
    void saveFile();

    //统计文件中的职工数目
    int getEmpNum();

    //显示职工
    void show_Emp();

    //删除职工
    void del_Emp();

    // 根据职工编号判断员工是否在文件中，若存在返回下标，不存在则返回-1
    int IsExist(int id);

    //修改职工
    void update_Emp();

    //查找职工
    void find_Emp();

    //排序职工
    void sort_Emp();
    
    //清空员工
    void clean_Emp();

    
    ~WorkerManager();

    //记录文件中的职工数量
    int m_EmpNum;

    //存放员工数组的指针
    Worker ** m_EmpArray;

    //判断文件是否为空的标志
    bool m_FileIsEmpty;
};


