#include<iostream>
using namespace std;
#include<list>

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

bool comparePerson(Person &p1, Person &p2){
    if (p1.m_Age == p2.m_Age)
    {   
        //年龄相同按照身高降序
        return p1.m_Height > p2.m_Height;
    }
    //按照年龄升序
    return p1.m_Age < p2.m_Age;
}

void test01(){
    list<Person> L;
    L.push_back(Person("tom", 18, 180));
    L.push_back(Person("jerry", 19, 180));
    L.push_back(Person("adam", 25, 180));
    L.push_back(Person("jack", 16, 180));
    L.push_back(Person("uzi", 16, 185));

    cout<<"排序前："<<endl;
    for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout<<"姓名："<<it->m_Name<<"\t年龄："<<it->m_Age<<"\t身高："<<it->m_Height<<endl;
    }
    cout<<"排序后："<<endl;
    L.sort(comparePerson);
    for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout<<"姓名："<<it->m_Name<<"\t年龄："<<it->m_Age<<"\t身高："<<it->m_Height<<endl;
    }

}

int main(){
    test01();
    system("pause");
    return 0;
}