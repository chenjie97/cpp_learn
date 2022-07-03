#include "workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

WorkerManager::WorkerManager()
{	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1、存放员工信息的文件不存在
	if( !ifs.is_open() )
	{
		// cout<<"文件不存在"<<endl;
		this->m_EmpNum = 0;//先初始化0，后续要显示文件中的职工数量
		this->m_EmpArray = NULL; //先指向空，后续要根据文件初始化
		this->m_FileIsEmpty = true; //将标志定义为空。
		ifs.close();
		return;
	}

	//2、存放员工信息的文件存在但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// cout<<"文件为空"<<endl;
		this->m_EmpNum = 0;//先初始化0，后续要显示文件中的职工数量
		this->m_EmpArray = NULL; //先指向空，后续要根据文件初始化
		this->m_FileIsEmpty = true; //将标志定义为空。
		ifs.close();
		return;
	}
	ifs.close();

	ifstream ifs_; //注意这里变量的命名 要与前面的流对象名称不同
	ifs_.open(FILENAME, ios::in);
	//3、存放员工信息的文件存在并且有数据
	int num = this->getEmpNum();
	// cout<<"职工人数为："<<num<<"人。"<<endl;
	//初始化参数
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	int id, did;
	string name;
	int idx = 0;
	while (ifs_>>id && ifs_>>name && ifs_>>did)
	{
		Worker * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (did == 1)  // 1-普通员工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2) //2-经理
		{
			worker = new Manager(id, name, did);
		}
		else //3-老板
		{
			worker = new Boss(id, name, did);
		}
		//存放在数组中
		this->m_EmpArray[idx] = worker;
		idx++;
	}
	ifs_.close();
	
	
	

}

void WorkerManager::showMenu(){
    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem(){
	cout<<"欢迎下次使用"<<endl;
	system("pause");
	exit(0); //退出程序，return是退出当前函数
}

//添加职工
void WorkerManager::addEmp(){
	cout<<"请输入要添加的员工数量："<<endl;
	int addNum = 0;
	cin >> addNum;
	if( addNum>0 ){
		// 添加员工
		//1、首先要计算新空间的大小，并创建新的员工数组指针
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];
		//2、判断m_EmpArray是否为空，若不为空需要将原本的m_EmpArray先添加到新开辟的员工数组指针上
		if( m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//3、根据要添加的员工数量，循环在newSpace员工数组里面添加员工
		for (int i = 0; i < addNum; i++)
		{
			int ID;
			string name;
			int deptID;
			cout<<"请输入第"<< i+1 <<"个员工的职工编号："<<endl;
			cin >>ID;
			cout<<"请输入第"<< i+1 <<"个员工的职工姓名："<<endl;
			cin >> name;
			cout<<"请输入第"<< i+1 <<"个员工的职工岗位："<<endl;
			cout<<"1-普通员工"<<endl;
			cout<<"2-经理"<<endl;
			cout<<"3-老板"<<endl;
			cin>>deptID;

			// 首先根据不同的deptID创建员工对象，利用多态：父类指针指向子类对象
			Worker * w = NULL;
			switch (deptID)
			{
			case 1:
				w = new Employee(ID,name,1);
				break;
			case 2:
				w = new Manager(ID,name,2);
				break;
			case 3:
				w = new Manager(ID,name,3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = w;

		}
		
		//4、释放旧空间m_EmpArray
		delete[] this->m_EmpArray;
		// 为什么不释放刚刚在堆区开辟的w对象呢？因为这些员工对象存储在newSpace上，之后添加员工函数调用结束之后还是会用到的。
		// 所以开辟在这里的w对象要在整个workermanager对象析构的时候进行释放

		//5、更新参数
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		
		cout<<"成功添加"<<addNum<<"名员工！"<<endl;

		this->saveFile();//调用保存文件的函数

	}
	else
	{
		cout<<"输入有误！"<<endl;
	}
	
}

//保存职工信息到文件
void WorkerManager::saveFile(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs<<this->m_EmpArray[i]->m_ID<<"\t"
		   <<this->m_EmpArray[i]->m_Name<<"\t"
		   <<this->m_EmpArray[i]->m_DeptID<<endl;
	}
	ofs.close();
	

}

//统计文件中的职工数目
int WorkerManager::getEmpNum(){
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout<<"open failed!"<<endl;
	}
	else
	{
		string buf;
		int num = 0;
		while (getline(ifs, buf))
		{
			// cout<<buf<<endl;
			num++;
		}
		return num;
	}
	
	

}

//显示职工
void WorkerManager::show_Emp(){
	if(this->m_FileIsEmpty)
	{
		cout<<"当前没有职工!"<<endl;
		return;
	}

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//利用多态调用程序接口
		this->m_EmpArray[i]->showInfo();
	}
}

//删除职工
void WorkerManager::del_Emp(){
	if (this->m_FileIsEmpty)
	{
		cout<<"文件不存在或者记录为空"<<endl;
		return;
	}
	cout<<"请输入要删除的职工编号："<<endl;
	int id;
	cin>>id;
	//1、判断要删除的员工是否在文件当中
	int ret = this->IsExist(id);
	//2、删除员工
	if (ret != -1)
	{
		delete this->m_EmpArray[ret];
		for (int i = ret; i < this->m_EmpNum - 1; i++)
		{
			
			this->m_EmpArray[i] = this->m_EmpArray[i+1];
		}
		this->m_EmpNum--;
		//数据更新同步到文件中
		this->saveFile();
		cout<<"删除职工信息成功！"<<endl;
	}
	else{
		cout<<"职工管理系统中不存在此员工！"<<endl;
	}
	
}

int WorkerManager::IsExist(int id){
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			return i;
		}
	}
	return -1;
	
}

//修改职工
void WorkerManager::update_Emp(){
	if (this->m_FileIsEmpty)
	{
		cout<<"文件不存在或者文件为空"<<endl;
		return;
	}
	int id,did;
	string name;
	cout<<"请输入你想修改的员工编号："<<endl;
	cin >> id;
	cout<<"请输入你想修改的员工姓名："<<endl;
	cin >> name;
	cout<<"请输入你想修改的员工岗位编号："<<endl;
	cin >> did;
	//判断员工是否在文件中
	int ret = this->IsExist(id);
	if (ret != -1)
	{
		//下面的从代码上来看是没问题的，但是从设计逻辑上是不对的，一个worker声明的那时候就已经决定了他是employee、manager或者boss
		//所以只能删除woker重新创建。
		// this->m_EmpArray[ret]->m_ID = id;
		// this->m_EmpArray[ret]->m_Name = name;
		// this->m_EmpArray[ret]->m_DeptID = did;
		delete this->m_EmpArray[ret];
		Worker * worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, 1);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, 2);
		}
		else
		{
			worker = new Boss(id, name, 3);
		}
		this->m_EmpArray[ret] = worker;
		cout<<"修改成功！"<<endl;
		//更新到文件中
		this->saveFile();
	}
	else
	{
		cout<<"职工管理系统中查无此人"<<endl;
	}
	
	
}

//查找职工
void WorkerManager::find_Emp(){
	if (this->m_FileIsEmpty)
	{
		cout<<"文件不存在或者职工信息为空！"<<endl;
		return;
	}
	cout<<"请输入查找的方式："<<endl;
	cout<<"1-按职工编号查找"<<endl;
	cout<<"2-按职工姓名查找"<<endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		int id;
		cout<<"请输入要查找的职工编号："<<endl;
		cin>>id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout<<"查无此人！"<<endl;
		}
		
	}
	else if (select == 2)
	{
		string name;
		cout<<"请输入要查找的职工姓名："<<endl;
		cin>>name;
		bool notFound = true;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				this->m_EmpArray[i]->showInfo();
				if (notFound)
				{
					notFound = false;
				}
				
			}
		}
		if (notFound)
		{
			cout<<"查无此人！"<<endl;
		}
		
		
	}
	else
	{
		cout<<"输入选项有误！"<<endl;
	}
	
	
	
}

//排序职工
void WorkerManager::sort_Emp(){
	if (this->m_FileIsEmpty)
	{
		cout<<"文件不存在或者为空！"<<endl;
		return;
	}
	for (int i = 0; i < this->m_EmpNum - 1; i++)
	{
		for (int j = 0; j < this->m_EmpNum - i -1; j++)
		{
			if (this->m_EmpArray[i]->m_ID > this->m_EmpArray[i+1]->m_ID)
			{
				Worker * temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
				this->m_EmpArray[i+1] = temp;
			}
			
		}
	}
	// for (int k = 0; k < this->m_EmpNum; k++)
	// {
	// 	this->m_EmpArray[k]->showInfo();
	// }
	this->saveFile();
	this->show_Emp();
	
	
}

//清空员工
void WorkerManager::clean_Emp(){
	if (this->m_FileIsEmpty)
	{
		cout<<"当前文件不存在或者为空，无需重复操作！"<<endl;
		return;
	}
	cout<<"确定要清空员工文件吗？"<<endl;
	cout<<"1-确认"<<endl;
	cout<<"2-取消"<<endl;
	int select;
	cin>>select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//trunc代表删除文件后在创建
		ofs.close();

		//释放内存，更新参数
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//删除堆区的每个worker对象指针
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}	
			}
			//删除员工数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		
		
	}
	else
	{
		cout<<"已取消清空操作！"<<endl;
		return;
	}
	
	
	
}

//析构函数
WorkerManager::~WorkerManager()
{
	//释放开辟在堆区的内存
	if(this->m_EmpArray != NULL){

		//先把员工数组里面的worker子类对象给释放掉
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		//然后再释放员工数组
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}