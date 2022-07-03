#include<iostream>
using namespace std;

int main(){
    //  起始表达式；条件表达式；末尾循环体
    for (int i = 1; i <= 100; i++)
    {
        // 等于7     7的倍数    个位数是7   十位数是7
        if (i==7 or i%7==0 or i%10 == 7 or i/10%10 == 7)
        {
            cout << i <<"敲桌子"<< endl;
        }
        
        
    }
    

    system("pause");
    return 0;
}