#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
#### 5.2.5 count
**功能描述：**
* 统计元素个数, 返回int类型数据

**函数原型：**
- `count(iterator beg, iterator end, value);  `
  // beg 开始迭代器
  // end 结束迭代器
  // value 统计的元素
*/

//内置数据类型
void test01(){
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
    int num = count(v.begin(), v.end(), 4);
    cout<<"4出现了："<<num<<"次！"<<endl;
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

void test02(){
    vector<Person> v;
    v.push_back(Person("tom",18));
    v.push_back(Person("jerry",18));
    v.push_back(Person("jack",18));
    v.push_back(Person("adam",18));
    v.push_back(Person("jerry",18));
    int num = count(v.begin(), v.end(), Person("jerry",18));
    cout<<"jerry出现了："<<num<<"次！"<<endl;
}

int main(){
    // test01();
    test02();
    system("pause");
    return 0;
}