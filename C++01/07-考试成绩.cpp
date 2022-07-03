#include<iostream>
using namespace std;
#include<string>

int main(){

    int score[3][3] = {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };
    string names[] = {"tom","jerry","kate"};
    int row = sizeof(score)/sizeof(score[0]);
    int col = sizeof(score[0])/sizeof(score[0][0]);

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += score[i][j];
        }
        cout <<names[i]<<"的分数为： "<<sum<<endl;
        
    }
     



    system("pause");
    return 0;
}