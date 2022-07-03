#include<iostream>
using namespace std;

/*
    数组中的元素都是相同的数据类型
    数组是放在连续的内存位置的
    如果在初始化数组时，没有全部填写完会用0来填补数据[整形数组]  int arr2[3] = {1,2}; 等价于 int arr2[3] = {1,2,0};
    定义数组的时候必须指定数组的长度，这个长度可以通过赋值的个数进行推断（如方式3）

    数组名是一个常量，不能进行赋值操作

*/

int main(){
    // 定义方式1：
    int arr1[3];
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    // cout << arr1[0]<< endl;
    // cout << "数组的长度为：" << end(arr1)-begin(arr1) << endl;

    // 定义方式2：
    int arr2[3] = {1,2,3};
    for (int i = 0; i < end(arr2)-begin(arr2); i++)
    {
        cout <<arr2[i]<<endl;
    }

    // 定义方式3：
    cout <<"arr3:"<<endl;
    int arr3[] = {1,2,3,4,5};
    for (int i = 0;i< ( sizeof(arr3) / sizeof(arr3[0]) ); i++)
    {
        cout << arr3[i] << endl;
    }

    system("pause");
    return 0;
}