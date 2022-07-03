#include<iostream>
using namespace std;
/*
switch语句的优缺点：
优点：结构清晰，执行效率要高于if语句
缺点：switch的判断条件只能是一个整形或者字符型，不能支持区间操作。

注意事项：case中如果没写break 程序会一直向下执行所有的case中的代码。
*/


int main(){
    cout <<"please input a number:"<<endl;
    int num = 0;
    cin >> num;

    switch (num) // switch语句括号中的表达式只能是：整型、字符型、枚举型，且case语句后面的常量表达式的类型必须一致。
    {
    case 10: // 每一个case语句后面的常量表达式必须互不相同，
            //注意：在C++中字符型变量（char）并不是把字符本身放到内存中存储,而是会把字符对应的ASCII码放入存储单元。
        cout << "excellent!"<<endl;
        break;
    case 9:
        cout << "excellent!"<<endl;
        break;
    case 8:
        cout << "good!"<<endl;
        break;
    
    default:
        cout << "try again!"<<endl;
        break;
    }

    system("pause");
    return 0;
}