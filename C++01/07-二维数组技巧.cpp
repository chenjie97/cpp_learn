#include <iostream>
using namespace std;

int main(){

    int arr[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    // 1、统计内存占用空间大小
    cout <<"二维数组占用的空间内存："<< sizeof(arr) <<endl;
    cout <<"二维数组一行占用的内存为："<<sizeof(arr[0])<<endl;
    cout <<"一个元素占用的内存为："<<sizeof(arr[0][0])<<endl;

    // 2、统计行列数
    cout <<"arr的行数为："<<sizeof(arr)/sizeof(arr[0])<<endl;
    cout <<"arr的列数为："<<sizeof(arr[0])/sizeof(arr[0][0])<<endl;

    // 3、查看地址
    cout <<"二维数组的首地址为："<< (long long)arr <<endl;
    cout <<"二维数组第一行的首地址为："<< (long long)arr[0] <<endl;
    cout <<"二维数组第一个元素的首地址为："<< (long long)&arr[0][0] <<endl; //需要添加取址符 &



    system("pause");
    return 0;
}