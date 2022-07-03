#include "employee.h"



Employee::Employee(int ID, string name, int deptID){
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = deptID;
}

//显示职工信息的成员函数声明，此处的virtual关键字不加。
void Employee::showInfo(){
    cout<<"职工编号："<<this->m_ID
        <<"\t职工姓名："<<this->m_Name
        <<"\t岗位："<<this->getDeptName()
        <<"\t岗位指责：完成经理交代的任务。"<<endl;
        
}

//获取岗位名称
string Employee::getDeptName(){
    return "员工";
}