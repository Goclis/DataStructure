/*
    Date: 2014/04/19
    Author: Goclis Yao
    Email: goclisyyh@gmail.com
    Description: ����ʵ�ָ������򡣡�
*/

#ifndef SORT_H_
#define SORT_H_

namespace goclis_sort {
    template <typename T>
    void SelectionSort(T [], int); // ѡ������
    
    template <typename T>
    void Swap(T [], int, int); // ��������Ԫ��
}

template <typename T>
void goclis_sort::SelectionSort(T arr[], int len) {
    int i, j;
    for (i = 0; i < len; ++i) {
        int tmp = i; // ������Сֵ�����±�
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