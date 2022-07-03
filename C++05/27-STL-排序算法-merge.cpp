#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
merge
**功能描述：**
* 两个容器元素合并，并存储到另一容器中
  // 容器元素合并，并存储到另一容器中
  // 注意: 两个容器必须是**有序的**，返回的结果也是有序的

**函数原型：**
- `merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
  // beg1   容器1开始迭代器
  // end1   容器1结束迭代器
  // beg2   容器2开始迭代器
  // end2   容器2结束迭代器
  // dest    目标容器开始迭代器
*/
void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i+10);
        v2.push_back(i+20);
    }
    cout<<"v1:"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;

    cout<<"v2:"<<endl;
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<endl;

    vector<int> v3;
    v3.resize(v1.size()+v2.size());//开辟空间！！！！
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    cout<<"v3:"<<endl;
    for_each(v3.begin(), v3.end(), myPrint);
    cout<<endl;
}


int main(){
    test01();
    system("pause");
    return 0;
}