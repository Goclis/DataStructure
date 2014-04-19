/*
    Date: 2014/04/19
    Author: Goclis Yao
    Email: goclisyyh@gmail.com
    Description: 尽量实现各种排序。。
*/

#ifndef SORT_H_
#define SORT_H_

namespace goclis_sort {
    template <typename T>
    void SelectionSort(T [], int); // 选择排序
    
    template <typename T>
    void Swap(T [], int, int); // 交换两个元素
}

template <typename T>
void goclis_sort::SelectionSort(T arr[], int len) {
    int i, j;
    for (i = 0; i < len; ++i) {
        int tmp = i; // 本次最小值所在下标
        for (j = i + 1; j < len; ++j) {
            if (arr[tmp] > arr[j]) {
                tmp = j;
            }
        }
        if (tmp != i)
            goclis_sort::Swap(arr, i, tmp);
    }
}

template <typename T>
void goclis_sort::Swap(T arr[], int s, int k) {
    T tmp = arr[s];
    arr[s] = arr[k];
    arr[k] = tmp;
}

#endif // SORT_H_