#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

class Person
{
public:
    Person(string name, int score);
    string m_Name;
    int m_Score;
};

Person::Person(string name, int score)
{
    this->m_Name = name;
    this->m_Score = score;
}

void getScore(vector<Person> &v){
    int i = 1;
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {   
        deque<int> d;
        cout<<"请给第"<<i++<<"名选手"<<it->m_Name<<"打分："<<endl;
        for (int j = 1; j <= 10; j++)
        {
            int m_s = 0;
            cout<<"第"<<j<<"位评委打分："<<endl;
            cin >> m_s;
            d.push_back(m_s);
        }
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        int score = 0;
        for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
        {
            score += *(it);
        }
        (*it).m_Score = score/d.size();
        system("cls");
    }
}

void showScore(const vector<Person> &v){
    for (int i = 0; i < v.size(); i++)
    {
        int num = i+1;
        cout<<"第"<<num<<"位选手"<<v[i].m_Name<<"的最终得分是："<<v[i].m_Score<<endl;
    }
    
}

int main(){
    //1、创建5名选手，并存储到vector容器中
    vector<Person> personVec;
    personVec.push_back(Person("tom",0));
    personVec.push_back(Person("jack",0));
    personVec.push_back(Person("jerry",0));
    personVec.push_back(Person("adam",0));
    personVec.push_back(Person("uzi",0));
    //2、给5名选手打分
    getScore(personVec);
    //3、显示选手的最终得分
    showScore(personVec);

    system("pause");
    return 0;
}