#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
/*
**功能：双端数组，可以对头端进行插入删除操作

**deque与vector区别：**
* vector对于头部的插入删除效率低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度回比vector快
* vector访问元素时的速度会比deque快,这和两者内部实现有关\

*/

void printDeque(const deque<int> &deq){

    for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//deque的初始化方式
void test01(){
/*
* `deque<T>` deqT;                      //默认构造形式
* `deque(beg, end);`                  //构造函数将[beg, end)区间中的元素拷贝给本身。
* `deque(n, elem);`                    //构造函数将n个elem拷贝给本身。
* `deque(const deque &deq);`   //拷贝构造函数
*/
    deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
    printDeque(deq);

    deque<int> deq2(deq.begin(), deq.end());
    printDeque(deq2);

    deque<int> deq3(10,1);
    printDeque(deq3);

    deque<int> deq4(deq);
    printDeque(deq4);
}

//deque的赋值操作
void test02(){
/*
* `deque& operator=(const deque &deq); `         //重载等号操作符

* `assign(beg, end);`                            //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`                             //将n个elem拷贝赋值给本身。
*/
}

//deque的大小和vector一致，注意deque是没有容量这个概念的
void test03(){
/*
* `empty(); `                            //判断容器是否为空
* `size();`                              //返回容器中元素的个数
* `resize(int num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					              //如果容器变短，则末尾超出容器长度的元素被删除。
* `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				              //如果容器变短，则末尾超出容器长度的元素被删除
*/ 
}

//deque的插入和删除
void test04(){
/*
两端插入操作：
- `push_back(elem);`          //在容器尾部添加一个数据
- `push_front(elem);`        //在容器头部插入一个数据

- `pop_back();`                   //删除容器最后一个数据
- `pop_front();`                 //删除容器第一个数据


指定位置操作：
* `insert(pos,elem);`         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* `insert(pos,n,elem);`     //在pos位置插入n个elem数据，无返回值。
* `insert(pos,beg,end);`    //在pos位置插入[beg,end)区间的数据，无返回值。

* `clear();`                           //清空容器的所有数据
* `erase(beg,end);`             //删除[beg,end)区间的数据，返回下一个数据的位置。
* `erase(pos);`                    //删除pos位置的数据，返回下一个数据的位置。
*/
}

//deque的索引和vector一致

//deque的排序，借助算法sort()
void test05(){
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);
    sort(d.begin(), d.end());
    printDeque(d);
}

int main(){
    // test01();
    test05();
    system("pause");
    return 0;
}