#include<iostream>
using namespace std;
#include <typeinfo>
int main(){
    cout<< "hello" << endl;
    string s1 = "ABC";
    string s = "Teacher_";

    string s2 = s + s1[2];
    int a = 0;

    char c = 'z';
    
    // cout <<s2<<endl;
    // cout<<"Teacher_"+s1<<endl;
    // cout<<"Teacher_"+s1[2]<<endl;
    // cout<<"Teacher_"+c<<endl;
    // cout<<"Teacher_"+'z'<<endl;
    cout<<s+c<<endl;
    cout<< typeid(a).name() <<endl;
    system("pause");
    return 0;
}