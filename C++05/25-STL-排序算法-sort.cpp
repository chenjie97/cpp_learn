#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
sort
**功能描述：**
* 对容器内元素进行排序

**函数原型：**
- `sort(iterator beg, iterator end, _Pred);  `
  //  beg    开始迭代器
  //  end    结束迭代器
  // _Pred  谓词
*/
void myPrint(int val){
    cout<<val<<" ";
}

class MyCompare
{
public:
    bool operator()(int val1, int val2){
        return val1 > val2;
    }

};

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(70);
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;

    sort(v.begin(),v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;

    // sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
}



int main(){
    test01();
    system("pause");
    return 0;
}