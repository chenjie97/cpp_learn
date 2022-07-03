#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
binary_search
**功能描述：**
* 查找指定元素是否存在，查到 返回true  否则false
// 注意: 在**无序序列中不可用**


**函数原型：**
- `bool binary_search(iterator beg, iterator end, value);  `
  // beg 开始迭代器
  // end 结束迭代器
  // value 查找的元素
*/

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i+100);
    }
    sort(v.begin(), v.end());
    bool ret = binary_search(v.begin(), v.end(), 101);
    if (ret)
    {
        cout<<"找到了"<<endl;;
    }
    else
    {
        cout<<"没找到";
    }
    
    
}

int main(){
    test01();
    system("pause");
    return 0;
}