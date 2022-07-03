#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
**概念：返回bool类型的仿函数称为**谓词**
  如果operator()接受一个参数，那么叫做一元谓词
  如果operator()接受两个参数，那么叫做二元谓词
*/

void printVector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

class MyCompare
{
public:
    //二元谓词:重写函数调用运算符+返回值为bool+参数为两个
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};



void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(12);
    printVector(v);
    cout<<"---------------------"<<endl;
    sort(v.begin(), v.end());
    printVector(v);
    cout<<"---------------------"<<endl;
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);
}

int main(){
    test01();
    system("pause");
    return 0;
}