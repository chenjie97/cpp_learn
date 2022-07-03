#include"manager.h"

Manager::Manager(int ID, string name, int deptID){
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = deptID;
}

void Manager::showInfo(){
    cout<<"职工编号："<<this->m_ID
        <<"\t职工姓名："<<this->m_Name
        <<"\t岗位："<<this->getDeptName()
        <<"\t岗位指责：完成老板的指标，并给普通员工下达任务。"<<endl;

}

string Manager::getDeptName(){
    return "经理";
}