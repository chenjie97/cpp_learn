#include<iostream>
using namespace std;
#define MAX 1000

// 设计联系人的结构体
struct Person
{
    string m_Name;
    int m_Sex; //0代表女，1代表男
    int m_Age;
    string m_Phone;
    string m_Addr;
};


// 设计通讯录的结构体
struct AddressBooks
{
    struct Person personArray[MAX];
    int m_size; // 通讯录中保存了多少人
};


void showMenu(){
    cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(AddressBooks *book){
    // 判断通讯录是否已满
    if (book->m_size > MAX)
    {
        cout<<"通讯录已满!"<<endl;
        return;
    }
    string name;
    cout<<"请输入联系人姓名：";
    cin>>name;
    book->personArray[book->m_size].m_Name = name;

    cout<<"请输入联系人性别："<<endl;
    cout<<"0----女"<<endl;
    cout<<"1----男"<<endl;
    int sex;
    while (true)
    {   
        cin>>sex;
        if (sex==0 || sex==1)
        {
            book->personArray[book->m_size].m_Sex = sex;
            break; //输入对了就跳出死循环！
        }
        cout<<"请合法输入性别："<<endl;
    }

    cout<<"请输入联系人年龄：";
    int age;
    cin>>age;
    book->personArray[book->m_size].m_Age = age;

    cout<<"请输入联系人电话：";
    string phone;
    cin>>phone;
    book->personArray[book->m_size].m_Phone = phone;

    cout<<"请输入联系人住址：";
    string addr;
    cin>>addr;
    book->personArray[book->m_size].m_Addr = addr;
    
    book->m_size ++;
    cout<<"添加成功！"<<endl;

}

void showPerson(AddressBooks *book){
    int len = book->m_size;
    if (len==0)
    {
        cout<<"通讯录为空！";
        return;
    }
    
    for(int i=0; i<len; i++){
        cout<<"姓名："<<book->personArray[i].m_Name
        <<"\t性别："<<(book->personArray[i].m_Sex == 0 ? "女" : "男")
        <<"\t年龄："<<book->personArray[i].m_Age
        <<"\t电话："<<book->personArray[i].m_Phone
        <<"\t 地址："<<book->personArray[i].m_Addr<<endl;
    }
}

int isExist(AddressBooks *book, string name){
    // 判断联系人是否在通讯录中，若存在则返回位置下标，不存在则返回-1
    for (int i = 0; i < book->m_size; i++)
    {
        if(book->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *book){
    cout << "请输入要删除的联系人姓名：";
    string name;
    cin >> name;
    // 判断通讯录中有无该联系人
    int idx = isExist(book, name);
    if(idx == -1){
        cout<<"通讯录中没有此人！"<<endl;
        return;
    }
    // 删除联系人
    for(int i = idx; i<book->m_size-1 ; i++){
        book->personArray[i] = book->personArray[i+1];
    }
    book->m_size--;
    cout<<"删除成功！"<<endl;
}

void searchPerson(AddressBooks *book){
    cout<<"请输入要查找的联系人：";
    string name;
    cin >> name;
    int ret = isExist(book, name);
    if(ret == -1){
        cout<<"通讯录中查无此人！"<<endl;
    }
    else{
        cout<<"姓名："<<book->personArray[ret].m_Name
        <<"\t性别："<<(book->personArray[ret].m_Sex == 0 ? "女": "男")
        <<"\t年龄："<<book->personArray[ret].m_Age
        <<"\t电话："<<book->personArray[ret].m_Phone
        <<"\t住址："<<book->personArray[ret].m_Addr<<endl;
    }
    return;
}

void updatePerson(AddressBooks *book){
    cout<<"请输入要修改的联系人：";
    string name;
    cin >> name;
    int ret = isExist(book, name);
    if(ret == -1){
        cout<<"通讯录中查无此人！"<<endl;
    }
    else{
        cout<<"请重新输入联系人姓名：";
        cin>>name;
        book->personArray[ret].m_Name = name;

        cout<<"请重新输入联系人性别："<<endl;
        cout<<"0----女"<<endl;
        cout<<"1----男"<<endl;
        int sex;
        while (true)
        {   
            cin>>sex;
            if (sex==0 || sex==1)
            {
                book->personArray[ret].m_Sex = sex;
                break; //输入对了就跳出死循环！
            }
            cout<<"请合法输入性别："<<endl;
        }

        cout<<"请重新输入联系人年龄：";
        int age;
        cin>>age;
        book->personArray[ret].m_Age = age;

        cout<<"请重新输入联系人电话：";
        string phone;
        cin>>phone;
        book->personArray[ret].m_Phone = phone;

        cout<<"请重新输入联系人住址：";
        string addr;
        cin>>addr;
        book->personArray[ret].m_Addr = addr;
        }
        cout<<"修改成功！！"<<endl;
        return;
}

void cleanPerson(AddressBooks *book){
    book->m_size = 0; //逻辑上的清空操作！
    cout<<"通讯录已清空！！"<<endl;
}

int main(){

    // 创建通讯录结构体变量
    AddressBooks book;
    // 初始化通讯录
    book.m_size = 0;

    int select = 0;

    while (true)
    {   
        showMenu();
        cin>>select;
        switch (select)
        {
            case 1: 
                addPerson(&book); //地址传递，利用函数的形参修改main函数中的实参
                break;
            case 2:
                showPerson(&book);
                break;
            case 3:
                deletePerson(&book);
                break; 
            case 4:
                searchPerson(&book);
                break;
            case 5:
                updatePerson(&book);
                break;
            case 6:
                cleanPerson(&book);
                break; 
            case 0:
                cout<<"欢迎下次使用"<<endl;
                system("pause");
                return 0;
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
