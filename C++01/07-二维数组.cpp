#include <iostream>
using namespace std;

// 定义二维数组时可以省略行数，不能省略列数

int main(){
    // 二位数组的声明方式有四种
    // 1、方式一
    int arr1[2][2];
    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[1][0] = 3;
    arr1[1][1] = 4;
    cout <<"arr1:"<< endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout <<arr1[i][j]<<" ";
        }
        cout << endl;
    }
    
    // 2、方式二, 推荐！！！
    int arr2[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout <<"arr2:"<< endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout <<arr2[i][j]<<" ";
        }
        cout << endl;
        
    }
    // 3、方式三
    int arr3[2][3] = {0,1,2,3,4,5};
    cout <<"arr3:"<< endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout <<arr3[i][j]<<" ";
        }
        cout << endl;
        
    }
    // 4、方式四
    int arr4[][3] = {1,2,3,4,5,6}; 
    cout <<"arr4:"<< endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout <<arr4[i][j]<<" ";
        }
        cout << endl;
        
    }
    
    system("pause");
    return 0;
}