#include<iostream>
using namespace std;

void bubbleSort(int * arr, int n){ // 这里的int * arr 也可以写作 int arr[]
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

void printArray(int * arr, int n){
    for (int i = 0; i < n; i++)
    {
        // cout<<*arr++<<" ";
        cout<<arr[i]<<" ";//两种方式是等价的 //注意，指针指向数组时，是可以使用索引的，arr[i] 可以理解为 指针向后偏移至第i个元素的地址
    }
    cout<<endl;
}

     
int main(){
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,n);

    bubbleSort(arr, n);

    printArray(arr,n);

    system("pause");
    return 0;
}