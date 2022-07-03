#include<iostream>
#include<ctime>

using namespace std;

/*
循环语句：
1、while循环
2、do while循环
2、for循环
*/

int main(){

    srand( (unsigned int)time(NULL) ); //随机种子，按照系统时间生成随机数
    // 1、系统生成随机数
    int num = rand()%100 + 1; //随机生成一个1~100的

    // 2、玩家进行猜测
    int val = 0;
    cout <<"请猜测："<< endl;
    cin >> val;

    while (val != num)
    {
        if (val > num)
        {
            cout <<"你猜大了！"<< endl;
        }
        else
        {
            cout <<"你猜小了"<<endl;
        }
        cout <<"请继续猜测："<< endl;
        cin >> val;
        
    }
    cout <<"恭喜！ 你猜对了"<<endl;

    system("pause");
    return 0;
}