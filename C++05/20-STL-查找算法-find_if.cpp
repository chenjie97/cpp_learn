#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
/*
#### 5.2.2 find_if
**功能描述：**
* 按条件查找元素

**函数原型：**
- `find_if(iterator beg, iterator end, _Pred);  `
  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  // beg 开始迭代器
  // end 结束迭代器
  // _Pred 函数或者谓词（返回bool类型的仿函数）
*/

//查找内置数据类型
class greaterFive
{
public:
    bool operator()(int val){
        return val > 5;
    }

};
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator pos =  find_if(v.begin(), v.end(), greaterFive());
    if (pos == v.end())
    {
        cout<<"未查询到该val"<<endl;
    }
    else
    {
        cout<<"查询到："<<*pos<<endl;
    }
}

//查找自定义数据类型
class Person
{

public:
    Person(string name, int age);
    string m_Name;
    int m_Age;
    bool operator==(const Person& p);

};

Person::Person(string name, int age)
{
    this->m_Name = name;
    this->m_Age = age;
}
bool Person::operator==(const Person& p){
    if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Greater20
{
public:
    bool operator()(const Person& p){
        return p.m_Age > 16;
    }
};

void test02(){
    vector<Person> v;
    v.push_back(Person("tom", 18));
    v.push_back(Person("jerry", 16));
    v.push_back(Person("vim", 8));
    vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
    if (pos == v.end())
    {
        cout<<"未查询到该val"<<endl;
    }
    else
    {
        cout<<"查询到：姓名："<<pos->m_Name<<"\t年龄："<<pos->m_Age<<endl;
    }
}

int main(){
    // test01();
    test02();

    system("pause");
    return 0;
}