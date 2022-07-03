#include<iostream>
using namespace std;

int main(){

    int score = 0;
    cout <<"please input a number as your score:"<<endl;
    cin >> score;
    if (score >= 90)
    {
        cout <<"excellent!"<<endl;
    }
    else if (score>=60)
    {
        cout <<"good!"<<endl;
    }
    else
    {
       cout <<"try again!"<<endl;
    }

    system("pause");
    return 0; 

}