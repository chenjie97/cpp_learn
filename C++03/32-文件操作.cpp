#include<iostream>
using namespace std;
#include<fstream>
/*
C++中对文件操作需要包含头文件 <fstream>

文件类型分为两种：
1. **文本文件**     -  文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件** -  文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类:
1. ofstream：写操作
2. ifstream： 读操作
3. fstream ： 读写操作

文件打开方式：

| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式                 |

**注意：** 文件打开方式可以配合使用，利用|操作符
**例如：**用二进制方式写文件 `ios::binary |  ios:: out

c++判断文本文件为空，必须要先读一下文件（读一个字符），才能判断是否为空。
刚打开文件时，文件状态标识都是初始化状态，eof()函数是根据文件状态标识来判断当前是否到了文件尾，而不是用来判断文件是否为空。
当读取文件数据时，遇到文件尾时，系统会更改文件状态标识为文件尾，同时，返回EOF标志。
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{	
	}
*/

//写文件的步骤：
void test01(){
    //1、包含头文件
    //2、创建文件流对象
    ofstream ofs;
    //3、通过流对象打开文件
    ofs.open("test.txt", ios::out);
    //4、写数据
    ofs<<"姓名：Jay"<<endl;
    ofs<<"年龄：25"<<endl;
    //5、关闭流对象
    ofs.close();
}

//读文件的步骤：
void test02(){
    
    //1、包含头文件
    //2、创建文件流对象
    ifstream ifs;
    //3、打开文件并判断是否打开成功
    ifs.open("empFile.txt", ios::in);

    if( !ifs.is_open() ){
        //打开文件失败
        cout<<"open failed!!"<<endl;
        return;
    }
    //4、读数据（4中方式）

    //第一种
    // char buf[1024] = {0};
    // while ( ifs>>buf ) // ifs对象会按行(因为这里buf的size很大所以会按行读)把数据放到buf里面，读到头会返回一个false
    // {
    //     cout<<buf<<endl;
    // }

    //第二种
    // char buf[1024] = {0};
    // while ( ifs.getline(buf, sizeof(buf)) ) // ifs对象会按行把数据放到buf里面，读到头会返回一个false
    // {
    //     cout<<buf<<endl;
    // }

    //第三种，全局函数getline()
    string buf;
    while (getline(ifs, buf))
    {
        cout<<buf<<endl;
    }

    //第四种，不推荐使用，按字符读，效率比较低。
    // char c;
    // while ( (c=ifs.get()) != EOF ){ //EOF: End of File  文件结束的标志
    //     cout<<c;
    // }   

    //5、关闭流对象
    ifs.close();
}



class Person
{
public:
    char m_Name[64];
	int m_Age;
};
//以二进制的方式写文件
void test03(){
    /*
    二进制方式写文件主要利用流对象调用成员函数write
    函数原型 ：ostream& write(const char * buffer,int len);
    参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
    */
   //1、包含头文件
   //2、创建流对象
   ofstream ofs;
   //3、打开文件
   ofs.open("Person.txt", ios::out | ios::binary);
   //4、写数据

   //若类和结构体所有数据成员均为public型，可采取如下带花括号形式进行初始化。
   Person p = {"张三", 18};
   ofs.write((const char *)&p, sizeof(p));
   //5、关闭流对象
   ofs.close();

}

//以二进制的方式读文件
void test04(){
    /*
    二进制方式读文件主要利用流对象调用成员函数read
    函数原型：`istream& read(char *buffer,int len);`
    参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
    */

   //1、包含头文件
   //2、创建流对象
   ifstream ifs;
   //3、打开文件，并判断是否成功打开
   ifs.open("Person.txt", ios::in | ios::binary);
   if(!(ifs.is_open())){
       cout<<"open failed!!"<<endl;
   }
   //4、读数据

   Person p;
   ifs.read((char *)&p, sizeof(p));
   cout<<p.m_Name<<endl;
   cout<<p.m_Age<<endl;
   //5、关闭流对象
   ifs.close();



}

int main(){
    // test01();
    test02();
    // test03();
    // test04();
    system("pause");
    return 0;
}