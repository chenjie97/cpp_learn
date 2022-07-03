#include<iostream>
#include<numeric> //需要导入numeric这个头文件
#include<vector>
using namespace std;
/*
算术生成算法属于小型算法，使用时包含的头文件为 `#include <numeric>`

accumulate
**功能描述：**
*  计算区间内 容器元素累计总和

**函数原型：**
- `accumulate(iterator beg, iterator end, value);  `
  // beg 开始迭代器
  // end 结束迭代器
  // value 起始值
*/

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int num = accumulate(v.begin(), v.end(), 0);
    cout<<num<<endl;
    
}

int main(){
    test01();
    system("pause");
    return 0;
}