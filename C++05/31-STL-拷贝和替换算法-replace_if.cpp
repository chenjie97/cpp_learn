#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
#### 5.4.3 replace_if
**功能描述:**  
* 将区间内满足条件的元素，替换成指定元素

**函数原型：**
- `replace_if(iterator beg, iterator end, _pred, newvalue);  `
  // beg 开始迭代器
  // end 结束迭代器
  // _pred 谓词
  // newvalue 替换的新元素
*/

void myPrint(int val){
    cout<<val<<" ";
}

class Greater20
{
public:
    bool operator()(int val){
        return val>5;
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    replace_if(v.begin(), v.end(), Greater20(), 100);
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;    
}


int main(){
    test01();
    system("pause");
    return 0;
}