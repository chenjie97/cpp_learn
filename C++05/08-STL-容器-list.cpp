#include<iostream>
using namespace std;
#include<list>

/*
list（链表）
STL中的链表是一个 双向循环链表
*/

void printList(const list<int> &L){
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//list的初始化方式
void test01(){
/*
* `list<T> lst;`                       //list采用采用模板类实现,对象的默认构造形式：
* `list(beg,end);`                     //构造函数将[beg, end)区间中的元素拷贝给本身。
* `list(n,elem);`                      //构造函数将n个elem拷贝给本身。
* `list(const list &lst);`             //拷贝构造函数。
*/
    list<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    printList(L);

    list<int> L2(L.begin(), L.end());
    printList(L2);

    list<int> L3(10,99);
    printList(L3);

    list<int> L4 = L3;
    printList(L4);
}

//list的赋值与交换
void test02(){
/*
* `assign(beg, end);`            //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`              //将n个elem拷贝赋值给本身。
* `list& operator=(const list &lst);`         //重载等号操作符
* `swap(lst);`                         //将lst与本身的元素互换。
*/
    list<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    printList(L);

    list<int>L2 = L; //等号重载
    printList(L2);

    list<int>L3;
    L3.assign(L.begin(),L.end());
    printList(L3);

    list<int> L4;
    L4.assign(10,99);
    printList(L4);

    list<int> L5;
    cout<<"交换前："<<endl;
    cout<<"L4:";
    printList(L4);
    cout<<"L5:";
    printList(L5);
    L4.swap(L5);
    cout<<"交换后："<<endl;
    cout<<"L4:";
    printList(L4);
    cout<<"L5:";
    printList(L5);
}

//list的大小
void test03(){
/*
* `size(); `                             //返回容器中元素的个数
* `empty(); `                           //判断容器是否为空
* `resize(num);`        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					     //如果容器变短，则末尾超出容器长度的元素被删除。

* `resize(num, elem); ` //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​					     //如果容器变短，则末尾超出容器长度的元素被删除。

*/
}

//list的插入和删除
void test04(){
/*
* push_back(elem);     //在容器尾部加入一个元素
* pop_back();          //删除容器中最后一个元素
* push_front(elem);    //在容器开头插入一个元素
* pop_front();         //从容器开头移除第一个元素

* insert(pos,elem);    //在pos位置插elem元素的拷贝，返回新数据的位置。
* insert(pos,n,elem);  //在pos位置插入n个elem数据，无返回值。
* insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。

* clear();             //移除容器的所有数据
* erase(beg,end);      //删除[beg,end)区间的数据，返回下一个数据的位置。
* erase(pos);          //删除pos位置的数据，返回下一个数据的位置。
* remove(elem);        //删除容器中所有与elem值匹配的元素。这个与python不一样，python是删除list中第一个elem
*/
}

//list的索引
void test05(){
/*
* `front();`        //返回第一个元素。
* `back();`         //返回最后一个元素。
*/
}

//list的反转与排序
void test06(){
/*
* `reverse();`   //反转链表
* `sort();`      //链表排序
*/
    list<int> L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(19);
    L1.push_back(20);
    L1.push_back(10);
    printList(L1);

    L1.reverse();
    printList(L1);

    L1.sort();
    //注意：不可以使用sort(L1.begin(),L1.end());来进行排序
    //原因是：所有不支持随机迭代器的容器，都不能用标准算法的sort()算法来进行排序
    printList(L1);
}


int main(){
    // test01();
    // test02();
    test06();
    system("pause");
    return 0;
}