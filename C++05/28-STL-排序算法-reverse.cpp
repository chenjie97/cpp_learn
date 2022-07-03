#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
/*
#### 5.3.4 reverse
**功能描述：**
*  反转指定范围的元素

**函数原型：**
- `reverse(iterator beg, iterator end);  `
  // beg 开始迭代器
  // end 结束迭代器
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

    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;


}


int main(){
    test01();
    system("pause");
    return 0;
}