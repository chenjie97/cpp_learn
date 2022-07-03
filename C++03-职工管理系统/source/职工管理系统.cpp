#include<iostream>
using namespace std;
#include "workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

void test01(){
    //test代码
    //多态：父类指针指向子类对象。
    // Worker w = Employee(1,"tom",1);//报错抽象类不能实例化对象
    // 但是可以实例化和抽象类对应的指针对象
    Worker * worker = new Employee(1,"tom",1);
    worker->showInfo();
    delete worker;
    worker = NULL; //变成空指针，避免野指针。

    worker = new Manager(2,"jerry",2);
    worker->showInfo();
    delete worker;
    worker = NULL; //变成空指针，避免野指针。

    worker = new Boss(3,"jay",3);
    worker->showInfo();
    delete worker;
    worker = NULL; //变成空指针，避免野指针。
}

int main(){
    
    // test01();

    WorkerManager wm;
    int choice;
    while (true)
    {   
        wm.showMenu();
        cout << "请输入您的选择："<<endl;
        cin >> choice;
        switch (choice)
        {
        case 0://退出系统
            wm.exitSystem();
            break;
        case 1://添加职工
            wm.addEmp();
            break;
        case 2://显示职工
            wm.show_Emp();
            break;
        case 3://删除职工
            wm.del_Emp();
            break;
        case 4://修改职工信息
            wm.update_Emp();
            break;
        case 5://查找职工
            wm.find_Emp();
            break;
        case 6://排序职工
            wm.sort_Emp();
            break;
        case 7://清空职工
            wm.clean_Emp();
            break;
        
        default:
        cout<<"非法操作！请重新输入！"<<endl;
            break;
        }
        system("pause"); //  请输入任意键继续
        system("cls"); // 清屏操作
    }
    


    system("pause");
    return 0; 
}