#include<iostream>
using namespace std;
#include<ctime>

struct Student
{
    string sName;
    int score;
};

struct Teacher
{
    string tName;
    struct Student sArray[5];
};
void allocateSpace(struct Teacher * tArray, int len){
    srand((unsigned int)time(NULL));
    string teacherName = "ABC";
    string studentName = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += teacherName[i];
        
        for (int j = 0; j < 5; j++)
        {   
            string name = "Student_";
            name += studentName[j];
            int random_score = rand() % 61 + 40;
            tArray[i].sArray[j] = {name, random_score};
        }
        
    }
    
}

void printInfo(struct Teacher tArray[], int len){
    for (int i = 0; i < len; i++)
    {
        cout<<"教师姓名："<<tArray[i].tName<<"\t";
        cout<<"该老师所带的学生信息："<<endl;
        
        for (int j = 0; j < 5; j++)
        {   
            cout<<"学生姓名："<<tArray[i].sArray[j].sName<<"\t学生分数："<<tArray[i].sArray[j].score<<endl;
        }
        cout<<endl;
        
    }
}

int main(){
    // 创建3名老师的数组
    struct Teacher tArray[3];
    int len = sizeof(tArray)/sizeof(tArray[0]);
    // 通过函数给3名老师的信息赋值，并将老师所带的学生进行复制
    allocateSpace(tArray, len);
    // 打印所有老师及所带学生的信息
    printInfo(tArray, len);


    system("pause");
    return 0;
}