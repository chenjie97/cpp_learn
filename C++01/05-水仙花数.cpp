#include<iostream>
using namespace std;

/*
什么是水仙花数？
    153 = 1^3 + 5^3 + 3^3； 个位、十位、百位的三次方和等于其自身值
则153为水仙花数.

Q：找到所有是水仙花数的三位数。

核心解题技巧为：如何获取一个数的个位，十位和百位。
    python可以用强制类型转换+字符串索引
    答案是：取模运算!!!!!!
*/

int main(){
    int num = 99;
    do
    {
        num++;
        
        // 求一个数的个位
        int a = num % 10;
        // 求一个数的十位
        int b = num/10 % 10;
        // 求一个数的百位
        int c = num/100 % 10;
        if (a*a*a + b*b*b + c*c*c == num)
        {
            cout <<num<<"是一个水仙花数"<<endl;
        }
        
    } while (num < 999);
    


    system("pause");
    return 0;
}