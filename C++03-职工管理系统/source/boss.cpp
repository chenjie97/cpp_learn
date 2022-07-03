#include"boss.h"

//构造函数
Boss::Boss(int ID, string name, int deptID){
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = deptID;
}

//显示职工信息
void Boss::showInfo(){
    cout<<"职工编号："<<this->m_ID
    <<"\t职工姓名："<<this->m_Name
    <<"\t岗位："<<this->getDeptName()
    <<"\t岗位指责：给经理下达任务。"<<endl;
}

//获取岗位名称
string Boss::getDeptName(){
    return string("老板");
}