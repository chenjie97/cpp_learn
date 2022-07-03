#include<iostream>
using namespace std;

/*
在C++中有两种字符串类型：
（1）C串
    char 变量名[] = "字符串值"   注意：C风格的字符串要用双引号括起来
（2）string
    string  变量名 = "字符串值" 注意：C++风格字符串，需要加入头文件 #include<string>
*/

int main(){
    char str1[] = "hello";
    cout <<"C风格字符串："<< str1<<endl; //有别于普通数组，输出变量名不会得到地址而是得到字符串的内容

    string str2 = "world";
    cout <<"string:"<<str2<<endl;

    system("pause");
    return 0;
}