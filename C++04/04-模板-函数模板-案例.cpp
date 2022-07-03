#include<iostream>
using namespace std;
#include<string.h>
/*
案例描述：

* 利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
* 排序规则从大到小，排序算法为**选择排序**
* 分别利用**char数组**和**int数组**进行测试

*/
template<class T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void showArray(T arr[], int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

template<class T>
void mySort(T arr[], int len){

    //选择排序：每次都把最小值放到最前面，类似于插扑克牌
    for (int i = 0; i < len - 1; i++)
    {
        int minIdx = i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
            
        }
        if (minIdx != i)
        {
            mySwap(arr[i], arr[minIdx]);
        }
    }
    showArray(arr,len);
}



void test01(){
    char charArr[] = "bdcfeagh";//注意： 用字符串初始化字符数组时，"\0"附带在后面与前面的字符一起作为字符数组的元素。
    // 用字符串初始化字符数组时，系统会在字符数组的末尾自动加上一个字符"\0"，因此数组的大小比字符串中实际字符的个数大
    // 但是string 对象没有  ‘\0’

    // sizeof(str1)=strlen(str1) +1;
    // sizeof() 会计入‘\0’，strlen() 不会
    int n_char = sizeof(charArr)/sizeof(char) - 1 ;// 减一之后n_char也是8
    int n = strlen(charArr);// n=8
    int intArr[] = {2,4,1,3,5};
    int n_int = sizeof(intArr)/sizeof(int);
    mySort(charArr, n_char);
    mySort(intArr, n_int);
}

int main(){

    test01();
    system("pause");
    return 0;
}