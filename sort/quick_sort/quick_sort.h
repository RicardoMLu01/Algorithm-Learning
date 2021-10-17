/*************************************************************************
* @file: quick_sort.h
* @description: 快速排序基础及优化
* @author: xtx
* @data:  2021.9.20
 ************************************************************************/

#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <iostream>
#include <ctime>


int median_of_three(int *arr, int low, int high);//三数取中
void insert_sort(int *arr, int l, int r);//插入排序 

void quick_sort_v1(int *arr, int len);//需分配额外空间快排
void qSort_v1(int *arr, int n);
void quick_sort_v2(int *arr, int l, int r);//二路双指针快排
void qSort_v2(int *arr, int n);
void quick_sort_v3(int *arr, int l, int r);//二路+插排+三数取中
void qSort_v3(int *arr, int n);
void quick_sort_v4(int *arr, int l, int r);//单边递归
void qSort_v4(int *arr, int n);
void quick_sort_v5(int *arr, int l, int r);//三路快排
void qSort_v5(int *arr, int n);


#endif
