#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
count_if
**功能描述：**
* 按条件统计元素个数

**函数原型：**
- `count_if(iterator beg, iterator end, _Pred);  `
  // beg 开始迭代器
  // end 结束迭代器
  // _Pred 谓词
*/

class Greater20
{
public:
    bool operator()(int val){
        return val>20;
    }
};

//内置数据类型
void test01(){
    vector<int> v;
	v.push_back(10);
	v.push_back(220);
	v.push_back(40);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
    int num = count_if(v.begin(), v.end(), Greater20());
    cout<<"比20大的数出现了："<<num<<"次！"<<endl;
}

//自定义数据类型
class Person
{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    bool operator==(const Person& p){
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

class Greater18
{
public:
    bool operator()(Person& p){
        return p.m_Age > 18;
    }
};

void test02(){
    vector<Person> v;
    v.push_back(Person("tom",18));
    v.push_back(Person("jerry",19));
    v.push_back(Person("jack",18));
    v.push_back(Person("adam",20));
    v.push_back(Person("jerry",25));
    int num = count_if(v.begin(), v.end(), Greater18());
    cout<<"年龄比18大的人出现了："<<num<<"次！"<<endl;
}

int main(){
    // test01();
    test02();
    system("pause");
    return 0;
}