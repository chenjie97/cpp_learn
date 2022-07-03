#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5};
    // 1、获取数组长度
    // 为什么cpp没有提供一个函数来获取数组的长度呢？可能因为底层的设计原则，一个数组在初始化时就必须要指定数组的长度。
    int length_arr = sizeof(arr)/sizeof(arr[0]);
    cout <<"数组的长度为："<<length_arr<<endl;

    // 2、获取数组的首地址，直接输入数组的变量名称即可（访问可变数据类型变量名是内存地址）
    cout <<"数组的首地址为(16进制)："<< arr << endl;
    cout <<"数组的首地址为(10进制)："<< (long long)arr << endl;//cpp中的强制类型转换是：  （目标数据类型）变量名

    // 3、获取数组中某一元素的地址  &arr[0],如果没有&符号会直接显示元素的内容，而非地址（访问不可变数据类型的变量名是变量所代表的内容）
    cout <<"数组中第一个元素的地址为(10进制)："<< (long long)&arr[0] << endl;

    // 4、数组名是一个常量，不能进行赋值操作

    // 5、数组求最值
    int max_num = 0;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if (arr[i] > max_num)
        {
            max_num = arr[i];
        }
        
    }
    cout <<"数组的最大值为："<<max_num<<endl;

    // 6、数组元素逆置（倒序）
    cout <<"数组原始顺序为：";
    for (int i = 0; i < length_arr; i++)
    {
        cout <<arr[i]<<"\t";
    }
    cout << endl;
    for (int i = 0; i < length_arr / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[length_arr-1-i];
        arr[length_arr-1-i] = tmp;
    }
    cout <<"数组逆置顺序为：";
    for (int i = 0; i < length_arr; i++)
    {
        cout <<arr[i]<<"\t";
    }
    cout << endl;

    system("pause");
    return 0;
}