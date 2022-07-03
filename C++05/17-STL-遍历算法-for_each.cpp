#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
* 算法主要是由头文件`<algorithm>` `<functional>` `<numeric>`组成。

* `<algorithm>`是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
* `<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
* `<functional>`定义了一些模板类,用以声明函数对象。
*/

/*
for_each在实际开发中是最常用遍历算法，需要熟练掌握
函数原型：
`for_each(iterator beg, iterator end, _func);  `
// 遍历算法 遍历容器元素
// beg 开始迭代器
// end 结束迭代器
// _func 函数或者函数对象
*/
void print01(int val){
    cout<<val<<" ";
}

class Print02{

public:
    void operator()(int val){
        cout<<val<<" ";
    }

};

void test01(){

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    for_each(v.begin(), v.end(), print01);   //使用函数
    cout<<endl;
    for_each(v.begin(), v.end(), Print02()); //使用函数对象
    cout<<endl;

}

int main(){

    test01();

    system("pause");
    return 0;
}