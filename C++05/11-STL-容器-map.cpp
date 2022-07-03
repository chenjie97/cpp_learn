#include<iostream>
#include<map>
using namespace std;
/*
**简介：**
* map中所有元素都是《pair》
* pair中第一个元素为key（键），起到索引作用，第二个元素为value（值）
* 所有元素都会根据元素的key来<自动排序>

**本质：**
* map/multimap属于**关联式容器**，底层结构是用二叉树实现。

**优点：**
* 可以根据key值快速找到value值

map和multimap**区别**：
- map不允许容器中有重复key值元素
- multimap允许容器中有重复key值元素
*/
template<class T1, class T2>
void printMap(const map<T1, T2> &mp){
    //编译器把 map<T1,T2>::const_iterator it = mp.begin()认为是一个成员变量，而非是一个类型，加入关键字class后，被认为是一个类型。
    for (class map<T1,T2>::const_iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout<<"key："<<(*it).first<<"\tvalue："<<(*it).second<<endl;
    }
    cout<<endl;
}



//map容器的初始化方式和赋值操作
void test01(){
/*
**构造：**
* `map<T1, T2> mp;`                     //map默认构造函数: 
* `map(const map &mp);`             //拷贝构造函数

**赋值：**
* `map& operator=(const map &mp);`    //重载等号操作符
*/

    map<int,string> mp;
    //插入时会根据key来进行自动排序
    mp.insert(pair<int, string>(1,"tom"));
    mp.insert(pair<int, string>(3,"jay"));
    mp.insert(pair<int, string>(2,"jerry"));
    printMap(mp);

    map<int, string>m2(mp);
    printMap(m2);
}

//map容器的大小和交换操作,与set容器一样：不支持resize操作，因为resize的n很大的时候是需要补好多0的，这时候会有重复元素，不允许！
void test02(){
/*
- `size();`          //返回容器中元素的数目
- `empty();`        //判断容器是否为空
- `swap(st);`      //交换两个集合容器
*/
}

//map的插入和删除操作
void test03(){
/*
- `insert(elem);`           //在容器中插入元素。
- `clear();`                    //清除所有元素
- `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
- `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
- `erase(key);`            //删除容器中值为key的元素。
*/
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20)); //这种方式不需要写具体的数据类型
    printMap(m);
}

//map的查找和统计
void test04(){
/*
- `find(key);`      //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- `count(key);`     //统计key的元素个数
- `m[key]`          //获取键为key的值,不建议使用，若不存在键值为key的键值对，那么就要创建创建一个键为key，值为0的pair对组
*/
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20)); //这种方式不需要写具体的数据类型
    printMap(m);
    cout<<m[1]<<endl;
    cout<<m[100]<<endl;
    printMap(m);
}

//map的排序
class Mycompare
{
   
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
    
};



void test05(){
/*
- map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

**主要技术点:**
- 利用仿函数，可以改变排序规则
*/
    map<int,int,Mycompare> m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(5,50));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));

    for(map<int,int,Mycompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout<<"key："<<(*it).first<<"\tvalue："<<(*it).second<<endl;
    }
    cout<<endl;
}


int main(){
    // test01();
    // test03();
    // test04();
    test05();
    system("pause");
    return 0;
}