#include<iostream>
using namespace std;

int main(){
    // 利用指针访问数组中的元素
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int * p = arr; //数组的地址就是数组中第一个元素的地址，等价于：int * p = &arr[0];
    cout <<"利用指针访问第一个元素："<< *p <<endl;
    p++; //让指针向后偏移4个字节，为什么是四个字节呢？ 因为p这个指针在初始化的时候是整型的指针。
    cout <<"利用指针访问第二个元素："<< *p <<endl;

    cout <<"利用指针来遍历数组"<<endl;
    int * p2 = arr; 
    for (int i = 0; i < 10; i++)
    {
        cout << *p2++ <<endl; //注意：此处使用了后置加法，即先输出结果之后在进行++操作
    }
    int * p3 = arr; // 此处arr本质上也是一个指针
    for (int i = 0; i < 10; i++)
    {
        cout << p3[i] <<endl; //注意，指针指向数组时，是可以使用索引的，p3[i] 可以理解为 指针向后偏移至第i个元素的地址，并解引用
                              // p3[i]等价于arr[i]  这是因为arr本质上也是一个指针！！
    }
    



    system("pause");
    return 0;
}