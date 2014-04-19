#include "sort.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int a[7] = {3, 1, 2, 5, 9, 100, -1};

    goclis_sort::SelectionSort<int>(a, 7);

    for (int i = 0; i < 7; i++) {
        cout << a[i] << ' ';
    }
}