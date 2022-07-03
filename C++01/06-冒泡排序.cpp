#include<iostream>
using namespace std;

int main(){
    // 冒泡排序

    int arr[10] = {3,2,5,7,9,1,4,8,0,6};
    int n = sizeof(arr) / sizeof(arr[0]);


    cout <<"冒泡排序前："<<endl;    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 冒n-1次泡 
    for (int i = 0; i < n - 1; i++)
    {
        //每轮冒泡要比较几次元素
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            
        }
        
    }
    cout <<"冒泡排序后："<<endl;    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}