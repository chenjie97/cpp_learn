#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
#### 5.2.3 adjacent_find
**功能描述：**
* 查找相邻重复元素,返回相邻元素的第一个位置的迭代器

**函数原型：**
- `adjacent_find(iterator beg, iterator end);  `
  // beg 开始迭代器
  // end 结束迭代器
*/

void test01(){
    vector<int> v;
    v.push_back(0);
    v.push_back(10);
    v.push_back(10);
    v.push_back(0);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end())
    {
        cout<<"没有找到重复相邻元素"<<endl;
    }
    else
    {
        cout<<"找到相邻重复元素："<<*pos<<endl;
    }
    
    

}

int main(){
    test01(); 

    system("pause");
    return 0;
}