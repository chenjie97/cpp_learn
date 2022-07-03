#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
#### 5.4.2 replace
**功能描述：**
* 将容器内指定范围的旧元素修改为新元素

**函数原型：**
- `replace(iterator beg, iterator end, oldvalue, newvalue);  `
  // beg 开始迭代器
  // end 结束迭代器
  // oldvalue 旧元素
  // newvalue 新元素
*/
void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    replace(v.begin(), v.end(), 1, 100);
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;    
}

int main(){
    test01();
    system("pause");
    return 0;
}