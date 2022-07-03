#include<iostream>
using namespace std;

/*
引用做函数返回值的注意点：
1、不要做局部变量的返回值
2、函数的调用可以作为左值。为啥可以呢？是因为函数的返回值就是变量的一个引用，而一个变量的引用可以有多个（可以有多个别名）
*/


int& test01() {
	int a = 10; //局部变量
    return a;
}

int& test02(){
    static int a = 10; // 加上static关键字就会变成静态变量,存放在全局区，程序结束之后才会被释放！
    return a;
}

int main(){

    int &ref = test01(); // 返回的引用是局部变量，存放在内存的栈区。函数运行结束之后会被编译器释放

    cout<<"ref = "<< ref <<endl;// 第一次是正确的是因为编译器做了保留还没有释放内存
    cout<<"ref = "<< ref <<endl;// 第二次可能就会因为栈区内存释放而报错


    int &ref02 = test02();
    cout<<"ref02 = "<< ref02 <<endl; // 此时是没问题的

    test02() = 1000;//2、函数的调用可以作为左值
    cout<<"ref02 = "<< ref02 <<endl;

    system("pause");
    return 0;
} 