#include<iostream>
#include<set>
using namespace std;
/*
set(集合): 所有元素都会在插入时自动被排序

**本质：**
* set/multiset属于**关联式容器**，底层结构是用**二叉树**实现。

**set和multiset区别**：
* set不允许容器中有重复的元素
* multiset允许容器中有重复的元素
*/
void printSet(const set<int> &s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}


//set的初始化方式和赋值操作
void test01(){
    set<int> s1;
    s1.insert(30);
    s1.insert(10); //注意插入数据只能用insert
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    //set容器的特点：不允许有重复值；会自动排序。
    printSet(s1);

    set<int> s2(s1);//拷贝构造
    printSet(s2);
    
    set<int> s3;
    s3 = s1;
    printSet(s3);

}

//set的大小和交换，注意set容器没有resize()
void test02(){
/*
* `size();`          //返回容器中元素的数目
* `empty();`        //判断容器是否为空
* `swap(st);`      //交换两个集合容器
*/
}

//set的插入和删除
void test03(){
/*
* `insert(elem);`           //在容器中插入元素。
* `clear();`                    //清除所有元素
* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
* `erase(elem);`            //删除容器中值为elem的元素。
*/
}

//set的查找和统计
void test04(){
/*
* `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
* `count(key);`                //统计key的元素个数
*/
    set<int> s1;
    s1.insert(10);
    s1.insert(12);
    s1.insert(20);
    s1.insert(30);
    s1.insert(10);
    set<int>::iterator pos = s1.find(12);
    if (pos == s1.end())
    {
        cout<<"查无此元素！"<<endl;
    }
    else
    {   
        cout<<"包含此元素:"<<*pos<<endl;
    }
    printSet(s1);
    cout<<s1.count(10)<<endl;
}

//pair对组的创建，不需要包含头文件
void test05(){
/*
* `pair<type, type> p ( value1, value2 );`
* `pair<type, type> p = make_pair( value1, value2 );` //这种方式不需要写数据类型

获取数据使用：
p.first
p.secend
注意调用的是成员属性而不是成员方法
*/
}

//set容器排序
class MyCompare 
{
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void test06(){
/*
* set容器默认排序规则为从小到大，掌握如何改变排序规则
主要技术点：
* 利用仿函数，可以改变排序规则
*/
    set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//set容器自定义数据类型的排序，注意set容器使用自定义数据类型的时候必须要指定排序规则、
//因为set在插入元素的时候会进行排序，如果没有指定排序规则的话，就没办法插入元素。
class Person
{
public:
    Person(string name, int age, int height);
    string m_Name;
    int m_Age;
    int m_Height;
};

Person::Person(string name, int age, int height)
{
    this->m_Name = name;
    this->m_Age = age;
    this->m_Height = height;
}

class comparePerson
{
public:
    //形参里面的const修饰符不可以丢掉！！！！
    bool operator()(const Person &p1,const Person &p2){
        if (p1.m_Age == p2.m_Age)
        {
            return p1.m_Height > p2.m_Height;
        }
        
        return p1.m_Age < p2.m_Age;
    }
};

void test07(){
    set<Person, comparePerson> s;
    s.insert(Person("tom", 18, 180));
    s.insert(Person("jack", 17, 180));
    s.insert(Person("jason", 38, 180));
    s.insert(Person("jay", 16, 180));
    s.insert(Person("jerry", 20, 180));
    s.insert(Person("park", 20, 185));

    for(set<Person,comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout<<"姓名："<<it->m_Name<<"\t年龄："<<it->m_Age<<"\t身高："<<it->m_Height<<endl;
    }
}

int main(){
    // test01();
    // test02();
    // test04();
    // test06();
    test07();
    system("pause");
    return 0;
}