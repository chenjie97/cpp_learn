#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<ctime>

/*
#### 5.3.2 random_shuffle
**功能描述：**
* 洗牌   指定范围内的元素随机调整次序

**函数原型：**
- `random_shuffle(iterator beg, iterator end);  `
  // 指定范围内的元素随机调整次序
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
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

    random_shuffle(v.begin(), v.end());

    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    

}

int main(){
    srand((unsigned int)time(NULL)); //假如随机种子，这样每次运行的时候结果就会不一样
    test01();
    system("pause");
    return 0;
}