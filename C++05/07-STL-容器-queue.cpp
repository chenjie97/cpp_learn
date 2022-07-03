#include<iostream>
using namespace std;
#include<queue>
/*
queue(队列)：先进先出的数据结构

队列容器只允许从一端新增元素，从另一端移除元素

队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
队列中进数据称为 --- **入队**    `push`
队列中出数据称为 --- **出队**    `pop`
*/

void test01(){
    //初始化方式
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    queue<int> q2(q1);

    //赋值操作
    queue<int> q3 = q1;

    //数据存取
    q1.front();
    q1.back();
    q1.pop();

    //queue的大小
    q1.empty();
    q1.size();

}

int main(){
    test01();
    system("pause");
    return 0;
}