#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
vector与普通数组区别：不同之处在于数组是静态空间，而vector可以**动态扩展**.
动态扩展并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

*/
void printVector(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}


//vector的初始化方式
void test01(){
/*
构造函数原型：
 vector<T> v;                		     //采用模板实现类实现，默认构造函数
 vector(v.begin(), v.end());           //将v[begin(), end())区间中的元素拷贝给本身。
 vector(n, elem);                      //构造函数将n个elem拷贝给本身。
 vector(const vector &vec);            //拷贝构造函数。
*/
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    printVector(v1);

    vector<int> v2 = vector<int> (v1.begin(), v1.end());
    printVector(v2);

    vector<int> v3 = vector<int>(10, 99);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}

//vector赋值操作:等号赋值和assign()赋值
void test02(){
/*
* `vector& operator=(const vector &vec);`//重载等号操作符
* `assign(beg, end);`       //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`        //将n个elem拷贝赋值给本身。
*/
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v2.begin(), v2.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(8, 1);
    printVector(v4);

    
}

//vector的容量和大小
void test03(){
/*
* `empty(); `                            //判断容器是否为空
* `capacity();`                      //容器的容量
* `size();`                              //返回容器中元素的个数
* `resize(int num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					              //如果容器变短，则末尾超出容器长度的元素被删除。

* `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				              //如果容器变短，则末尾超出容器长度的元素被删除
*/
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    cout<<"vector是否为空："<<v1.empty()<<endl;
    cout<<"vector容量："<<v1.capacity()<<endl;
    cout<<"vector元素个数："<<v1.size()<<endl;

    v1.resize(13);//默认用0填充
    printVector(v1);

    v1.resize(3);//只保留前3个
    printVector(v1);

    v1.resize(13, 99);//使用99填充
    printVector(v1);
}

//vector的插入与删除操作
void test04(){
/*
* `push_back(ele);`                                 //尾部插入元素ele
* `pop_back();`                                     //删除最后一个元素
* `insert(const_iterator pos, ele);`                //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count,ele);`      //迭代器指向位置pos插入count个元素ele
* `erase(const_iterator pos);`                      //删除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
* `clear();`                                        //删除容器中所有元素
*/
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //插入
    v1.insert(v1.begin(), 99);
    printVector(v1);

    v1.insert(v1.begin(), 2, 99);
    printVector(v1);

    //删除
    v1.pop_back();//尾删
    printVector(v1);

    v1.erase(v1.begin());//删除单个元素
    printVector(v1);

    v1.erase(v1.begin(), v1.end());//删区间元素，左闭右开
    cout<<v1.empty()<<endl;;

    v1.clear(); //全部清空


}

//vector的索引
void test05(){
/*
* `at(int idx); `     //返回索引idx所指的数据
* `operator[]; `       //返回索引idx所指的数据
* `front(); `            //返回容器中第一个数据元素
* `back();`              //返回容器中最后一个数据元素
*/
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    //利用[]进行索引
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    
    //利用at()进行索引
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;

    cout<<v1.front()<<endl;;//第一个元素

    cout<<v1.back()<<endl;;//最后一个元素
    
    

}

//vector互换容器 swap(vec);  // 将vec与本身的元素互换
//学会利用swap来收缩内存
void test06(){
    vector<int> v;
	for (int i = 0; i < 100; i++) {
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//收缩内存
	vector<int>(v).swap(v); //匿名对象，当前行执行结束之后就会释放
    //具体过程：
    // vector<int>(v)  此时创建了一个匿名对象，假设起个名字叫x。
    // x.swap(v) 此时x与v内存互换，v变成容量只有3的x，x因为是匿名对象也会被删除

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

//vector预留空间
void test07(){
/*
减少vector在动态扩展容量时的扩展次数
`reserve(int len);`//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
	vector<int> v;

	//预留空间
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);

        //判断随着长度的增加，vector动态扩展了几次
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "num:" << num << endl;
}

//vector的排序
void test08(){
    vector<int> v;
    v.push_back(10);
    v.push_back(2);
    v.push_back(30);
    v.push_back(3);
    printVector(v);
    sort(v.begin(), v.end());
    printVector(v);
}

int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    test08();
    system("pause");
    return 0;
}