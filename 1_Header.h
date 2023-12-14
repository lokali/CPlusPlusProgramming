//
//  Header.h
//  Cexamples
//
//  Created by Longkang Li on 2019/8/8.
//  Copyright © 2019年 李隆康. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include<iostream>
#include<algorithm>
using namespace std;

int add(int a, int b){
    return (a+b);
}

int factorial(unsigned int n) //fabonacci
{
    unsigned long long fac = 1;
    
    
    for(int i = 1; i <=n; ++i)
    {
        fac *= i;
    }
    
    //cout << n << " 的阶乘为："<< " = " << fac;
    return (int)fac;
}

int HCF(int n1, int n2) //最大公约数
{

    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}

int LCM(int n1, int n2)//最小公倍数
{
    int max;
    max = (n1 > n2) ? n1 : n2;
    
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            break;
        }
        else
            ++max;
    } while (true);
    
    return max;
}

//不稳定算法：堆排序、快速排序、希尔排序、选择排序
//稳定算法：冒泡排序、插入排序、归并排序、基数排序

//冒泡排序：（把最大值放在最后面） 比较相邻的元素 把最大值放在最后一个。如果第一个比第二个大，就交换他们两个；
//对每一对相邻元素做相同的操作，从开始第一对到结尾的最后一对，这时最后的元素应该会是最大的数；对除了最后一个的所有元素重复以上步骤。
void bubbleSort(int arr[], int n){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j]>arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


//（Unstable）选择排序：（把最小值放在最前面）初始时，在序列中找到最小元素，放到序列的起始位置作为已排序序列；
//然后，再从剩余未排序元素中寻找最小元素，放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
//举个例子：序列5 8 5 2 9，我们知道第一遍选择第1个元素5会和2交换，那么原序列中2个5的相对前后顺序就被破坏了，所以选择排序不是一个稳定的排序算法。
void selectionSort(int arr[] , int n ){
    
    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j]<arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

    
//插入排序（包括直接插入和希尔排序）: （完成n-1次插入） 例如有一个长度为N的无序数组，进行N-1次的插入即能完成排序；
//第一次，数组第1个数认为是有序的数组，将数组第二个元素插入仅有1个有序的数组中
void insertionSort(int arr[], int n){
    
    for (int i = 1; i < n; i++){
        for (int j = i; j>0 ; j--){
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}


#endif /* Header_h */
