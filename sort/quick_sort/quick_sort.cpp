/*************************************************************************
* @file: quick_sort.cpp
* @description: 最基础版快速排序，需要分配额外内存空间
* @author: xtx
* @data:  2021.9.20
 ************************************************************************/

#include <iostream>
#include <ctime>
#include "quick_sort.h"

using namespace std;

//三数取中
int median_of_three(int *arr, int low, int high) {
	int mid = low + ((high - low) >> 1);
	if (arr[mid] > arr[high]) {
		swap(arr[mid], arr[high]);
	}
	if (arr[low] > arr[high]) {
		swap(arr[low], arr[high]);
	}
	if (arr[low] > arr[mid]) {
		swap(arr[low], arr[mid]);
	}
	return arr[mid];
}

//插入排序
void insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

/*基本思路： 分配两个待排数组长度内存空间，将小于pivot的放在左边，
		   将大于等于pivot的放在右边，持续递归下去，
		   最后把排好顺序的数组数据放回原数组
*/
void quick_sort_v1(int *arr, int len) {
    if (len <= 1) {
        return;
    }

    int *left = new int[len], *right = new int[len];    //最坏情况是选到最大数作为pivot
    int pivot = arr[0];
    int l = 0, r = 0;
    int index = 0;

    for (int i = 1; i < len; i++) {
        if (arr[i] < pivot) {
            left[l++] = arr[i];
        } else {
            right[r++] = arr[i];
        }
    }

    quick_sort_v1(left, l);
    quick_sort_v1(right, r);

    for (int i = 0; i < l; i++) {
        arr[index++] = left[i];
    }

    arr[index] = pivot;

    for (int i = 0; i < r; i++) {
        arr[++index] = right[i];
    }

    delete[] left;
    delete[] right;
    return;
}

void qSort_v1(int *arr, int n) {
    return quick_sort_v1(arr, n);
}

/*基本思路： 其中设置两个指针i，j(i从左边,j从右边)从两端向中间遍历， 
		   i遇到大于等于x的停下来，j遇到小于等于x的停下来，
		   然后如果(i<j)就交换q[i]，q[j]，之后结束循环，递归下去。
*/
void quick_sort_v2(int *arr, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1;   //i,j的初始化值是为了和后面的do-while对应
    int pivot = arr[l + r >> 1]; //推荐取值
	//后面递归边界情况讨论为了避免死循环，例如（1,2）和(2,1)
    //跳出循环有两种情况，1. i == j;（i，j相遇的值刚好等于pivot） 2. i = j + 1;（i,j相遇的值不等于pivot，擦肩而过）
    while (i < j) {    
        //用do-while是为了防止两边等于pivot时陷入死循环，每次交换完立即i+1,j-1 
        do i++; while (arr[i] < pivot);   //不加等号可以理解为，要满足交换后>=pivot，加等号后只满足>pivot
        do j--; while (arr[j] > pivot);
        //跳出循环时，j+1肯定>pivot，所以后面递归用j+1；同理i-1<pivot，所以用i递归时要用i-1
        if (i < j) swap(arr[i], arr[j]);
    }
	//当pivot=arr[l]时,sort(l,j),sort(j+1,r)
	//当pivot=arr[r]时,sort(l,i-1),sort(i,r)
	//当pivot=arr[l+r>>1]时，sort(l,j),sort(j+1,r)
    quick_sort_v2(arr, l, j);
    quick_sort_v2(arr, j + 1, r);
}

void qSort_v2(int *arr, int n) {
    return quick_sort_v2(arr, 0, n - 1);
}

/*基本思路： 在两路快排的基础上添加了三数取中和插排，三数取中是为了避免pivot取到最大值或者最小值，
		   影响快排效率；加入插排是因为插排在小数量数据情况下优于快排
*/
void quick_sort_v3(int *arr, int l, int r) {
	if (l >= r) return;
	if (r - l + 1 < 20) {	//小数据量时选择插入排序
		insert_sort(arr, l, r);
		return;
	}
    
    int i = l - 1, j = r + 1;   
    int pivot = median_of_three(arr, l, r);	//三数取中

    while (i < j) {    
        do i++; while (arr[i] < pivot);  
        do j--; while (arr[j] > pivot);
        if (i < j) swap(arr[i], arr[j]);
    }
    quick_sort_v3(arr, l, j);
    quick_sort_v3(arr, j + 1, r);
    return;
}

void qSort_v3(int *arr, int n) {
    return quick_sort_v3(arr, 0, n - 1);
}

/*基本思路： 有时候取值可能取到边界值，导致递归深度过深，为了减少递归深度，
		   采用了单边递归的方法
*/
void quick_sort_v4(int *arr, int l, int r) {
	if (l >= r) return;
	if (r - l + 1 < 20) {
		insert_sort(arr, l, r);
		return;
	}
    while (l < r) {
        int i = l - 1, j = r + 1;   
        int key = arr[l + r >> 1];

        while (i < j) {    
            do i++; while (arr[i] < key);  
            do j--; while (arr[j] > key);
            if (i < j) swap(arr[i], arr[j]);
        }
        quick_sort_v4(arr, l, j);
        l = j + 1;
    }
	return;
}

void qSort_v4(int *arr, int n) {
    return quick_sort_v4(arr, 0, n - 1);
}


/*基本思路： 在有大量重复元素的情况下，原本的二路快排效率较低，
			我们采用三路快排的方式
*/
// 递归的三路快速排序算法
void quick_sort_v5(int *arr, int l, int r){

    // 对于小规模数组, 使用插入排序进行优化
    if(r - l <= 15) {
        insert_sort(arr,l,r);
        return;
    }
    srand(time(NULL));
    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    int pivot = arr[l];

    int lt = l;     // arr[l+1...lt] < pivot
    int gt = r + 1; // arr[gt...r] > pivot
    int i = l + 1;    // arr[lt+1...i) == pivot
    while(i < gt) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[lt+1]);
            i ++;
            lt ++;
        }
        else if(arr[i] > pivot) {
            swap(arr[i], arr[gt-1]);
            gt --;
        }
        else { // arr[i] == pivot
            i ++;
        }
    }

    swap(arr[l], arr[lt]);

    quick_sort_v5(arr, l, lt-1);
    quick_sort_v5(arr, gt, r);
}

void qSort_v5(int *arr, int n) {
    return quick_sort_v5(arr, 0, n - 1);
}






