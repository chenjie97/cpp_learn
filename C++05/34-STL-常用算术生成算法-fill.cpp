#include<iostream>
#include<numeric> //需要导入numeric这个头文件
#include<vector>
using namespace std;
#include<algorithm>
/*
fill
**功能描述：**
* 向容器中填充指定的元素

**函数原型：**
- `fill(iterator beg, iterator end, value);  `
  // beg 开始迭代器
  // end 结束迭代器
  // value 填充的值
*/
void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    
}

int main(){
    test01();
    system("pause");
    return 0;
}