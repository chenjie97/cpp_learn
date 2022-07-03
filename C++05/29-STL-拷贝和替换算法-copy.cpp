#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
#### 5.4.1 copy
**功能描述：**
* 容器内指定范围的元素拷贝到另一容器中
//和transform的区别：transform除了搬运容器的元素外，还能进行增强操作！比如：取反等


**函数原型：**
- `copy(iterator beg, iterator end, iterator dest);  `
  // beg  开始迭代器
  // end  结束迭代器
  // dest 目标起始迭代器
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

    vector<int> vTarget;
    vTarget.resize(v.size());

    copy(v.begin(), v.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint);
    cout<<endl;    
}

int main(){
    test01();
    system("pause");
    return 0;
}