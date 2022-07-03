#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

/*
常用的查找算法
- `find`                     //查找元素
- `find_if`               //按条件查找元素
- `adjacent_find`    //查找相邻重复元素
- `binary_search`    //二分查找法
- `count`                   //统计元素个数
- `count_if`             //按条件统计元素个数
*/

/*
#### 5.2.1 find
* 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

**函数原型：**
- `find(iterator beg, iterator end, value);  `
  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  // beg 开始迭代器
  // end 结束迭代器
  // value 查找的元素
*/

//查找内置数据类型
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator pos =  find(v.begin(), v.end(), 1);
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

void test02(){
    vector<Person> v;
    v.push_back(Person("tom", 18));
    v.push_back(Person("jerry", 16));
    v.push_back(Person("vim", 8));
    vector<Person>::iterator pos = find(v.begin(), v.end(), Person("tom",18));
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