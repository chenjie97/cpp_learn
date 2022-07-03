#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
#### 5.4.4 swap
**功能描述：**
* 互换两个容器的元素

**函数原型：**
- `swap(container c1, container c2);  `
  // c1容器1
  // c2容器2
*/

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int> v;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        if (i <= 5)
        {
            v2.push_back(i+10);
        }
        
    }

    cout<<"交换前:"<<endl;
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl; 
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<endl; 

    swap(v,v2);

    cout<<"交换后:"<<endl;
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl; 
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<endl; 
}


int main(){
    test01();
    system("pause");
    return 0;
}