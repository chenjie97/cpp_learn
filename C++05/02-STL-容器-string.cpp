#include<iostream>
using namespace std;
#include<string>

/*
  string的本质是一个类
  c串的本质是一个指针【char*】
  ！！！！！！双引号括起来的就是c串： "hello world"  如果需要使用string类的方法，首先要将c串转化为string类型的对象

  // 注意： 用C串初始化字符数组时，"\0"附带在后面与前面的字符一起作为字符数组的元素，
  // 系统会在字符数组的末尾自动加上一个字符"\0"，因此数组的大小比字符串中实际字符的个数大
  // 但是string 对象没有  ‘\0’
  // sizeof(str1)=strlen(str1) +1;
  // sizeof() 会计入‘\0’，strlen() 不会
*/

//本函数是测试string容器的不同初始化方式。
void test01(){
  /*
  本函数是测试string容器的不同初始化方式。
  首先，string构造函数的原型有以下四种：
  string();                  //创建一个空的字符串 例如: string str;
  string(const char* s);     //使用字符串s初始化
  string(const string& str); //使用一个string对象初始化另一个string对象
  string(int n, char c);     //使用n个字符c初始化 
  */
  
  //第一种，无参构造
  string str1;
  cout<<"str1 = "<<str1<<endl;
  //第二种，有参构造-使用c串进行初始化
  char s[] = "hello world!--2"; //等价于 char* s = "hello world!--2";
  string str2(s);
  cout<<"str2 = "<<str2<<endl;
  //第三种，拷贝构造
  string s2 = "hello world!--3";
  string str3(s2);
  cout<<"str3 = "<<str3<<endl;
  //第四种，有参构造
  string str4(10,'a');
  cout<<"str4 = "<<str4<<endl;
}

//本函数是测试string的赋值操作。
void test02(){
  /*
  本函数是测试string的赋值操作。
    赋值的函数原型：
    * string& operator=(const char* s);             //char*类型字符串 赋值给当前的字符串
    * string& operator=(const string &s);         //把字符串s赋给当前的字符串
    * string& operator=(char c);                          //字符赋值给当前的字符串
    * string& assign(const char *s);                  //把字符串s赋给当前的字符串
    * string& assign(const char *s, int n);     //把字符串s的前n个字符赋给当前的字符串
    * string& assign(const string &s);              //把字符串s赋给当前字符串
    * string& assign(int n, char c);                  //用n个字符c赋给当前字符串
  总结：通常用 = 运算符，assign()可以用来将前n个字符进行赋值。
  */

  string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;


	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}

//本函数测试string容器的 拼接操作。
void test03(){
/*
* 实现在字符串末尾拼接字符串,主要是有两种方式：+= 和 append()
**函数原型：**
* `string& operator+=(const char* str);`                   //重载+=操作符
* `string& operator+=(const char c);`                         //重载+=操作符
* `string& operator+=(const string& str);`                //重载+=操作符
* `string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                           //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`   //字符串s中从pos开始的n个字符连接到字符串结尾
*/
}

//string类型的查找与替换（插入）
void test04(){
/*
* `int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找,若没有找到则返回-1
* `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
* `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
* `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
* `int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找。rfind是从右往左查找，但返回的下标还是从左往右。
* `int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
* `int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
* `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
* `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
* `string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串s
*/
  string str1 = "abcdefg";
  int pos = str1.find("de");
  cout<<"pos = "<<pos<<endl;

  str1.replace(1,3,"1111"); //从1号位置开始数三个，进行替换。
  cout<<"str1 = "<<str1<<endl;

  str1.replace(0,0,"插入字符"); //起始位置和长度参数设置为0的话相当于插入操作！！
  cout<<"str1 = "<<str1<<endl;
}

//c串和string类型之间的比较
void test05(){
  /*
  c串的变量名本质上是一个指针，指针由于指向得内存地址不同不会相同，所以相同内容的c串也是不同的。
  */
  char * str1 = "asdf"; //C++不建议使用这种方式声明
  char str2[] = "asdf";
  if (str1==str2)
  {
    cout<<"str1==str2"<<endl;
  }
  else
  {
    cout<<"str1!=str2"<<endl;//程序会进入此行。
  }

  string str3(str1);
  string str4(str2);
  if (str3==str4)
  {
    cout<<"str3==str4"<<endl;//程序会进入此行。
  }
  else
  {
    cout<<"str3!=str4"<<endl;
  }

  //compare():按字符的ASCII码进行对比
  // = 返回   0
  // > 返回   1 
  // < 返回  -1
  int ret = str3.compare(str4);
  if (ret == 0)
  {
    cout<<"相等"<<endl;
  }
  else if (ret == 1)
  {
    cout<<"str3 > str4"<<endl;
  }
  else
  {
    cout<<"str3 < str4"<<endl;
  }
  
  
  


  
  
  
}

//string类型的索引 和 修改
void test06(){
  /*
  两种方式：
  [] 和 at()
  */
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
	
}

//string类型的插入 和 删除
void test07(){
  /*
  * `string& insert(int pos, const char* s);  `                //插入字符串
  * `string& insert(int pos, const string& str); `        //插入字符串
  * `string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c
  * `string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符 
  */
}

//string类型的子串（切片）
void test08(){
  /*
  `string substr(int pos = 0, int n = npos) const;`   //返回由pos开始的n个字符组成的字符串
  */
 string str = "asdfgh";
 cout<<str.substr(1,2)<<endl;
}


int main(){
  // test01();
  // test02();
  // test04();
  // test05();
  // test06();
  test08();
  system("pause");
  return 0;
}