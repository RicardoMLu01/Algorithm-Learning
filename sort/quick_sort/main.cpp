/*************************************************************************
* @file: main.cpp
* @description: 测试快速排序程序性能
* @author: xtx
* @data:  2021.9.20
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <ctime>
#include "sort_helper.h"
#include "quick_sort.h"


using namespace std;

int main() {
	int n = 50000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
	int* arr4 = SortTestHelper::copyIntArray(arr1,n);
	int* arr5 = SortTestHelper::copyIntArray(arr1,n);

    // SortTestHelper::testSort("qSort_v1", qSort_v1, arr1, n); 
    SortTestHelper::testSort("qSort_v2", qSort_v2, arr2, n);
    SortTestHelper::testSort("qSort_v3", qSort_v3, arr3, n);
	SortTestHelper::testSort("qSort_v4", qSort_v4, arr4, n);
	SortTestHelper::testSort("qSort_v5", qSort_v5, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
	delete[] arr4;
	delete[] arr5;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);

    // SortTestHelper::testSort("qSort_v1", qSort_v1, arr1, n);
    SortTestHelper::testSort("qSort_v2", qSort_v2, arr2, n);
    SortTestHelper::testSort("qSort_v3", qSort_v3, arr3, n);
	SortTestHelper::testSort("qSort_v4", qSort_v4, arr4, n);
	SortTestHelper::testSort("qSort_v5", qSort_v5, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
	delete[] arr4;
	delete[] arr5;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);

    // SortTestHelper::testSort("qSort_v1", qSort_v1, arr1, n);
    SortTestHelper::testSort("qSort_v2", qSort_v2, arr2, n);
    SortTestHelper::testSort("qSort_v3", qSort_v3, arr3, n);
	SortTestHelper::testSort("qSort_v4", qSort_v4, arr4, n);
	SortTestHelper::testSort("qSort_v5", qSort_v5, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	return 0;
}