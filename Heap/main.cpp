#include "Heap.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    Heap<int> minHeap({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    minHeap.Print();
    while (!minHeap.Empty())
    {
        std::cout << minHeap.Pop() << " ";
    }
    std::cout << std::endl;

    Heap<int> minHeap2({});
    for (int i = 10; i >= 1; --i)
    {
        minHeap2.Insert(i);
    }
    minHeap2.Print();
    while (!minHeap2.Empty())
    {
        std::cout << minHeap2.Pop() << " ";
    }
    std::cout << std::endl;

    Heap<int> maxHeap({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false);
    maxHeap.Print();
    while (!maxHeap.Empty())
    {
        std::cout << maxHeap.Pop() << " ";
    }
    std::cout << std::endl;

    Heap<int> maxHeap2({}, false);
    for (int i = 1; i <= 10; ++i)
    {
        maxHeap2.Insert(i);
    }
    maxHeap2.Print();
    while (!maxHeap2.Empty())
    {
        std::cout << maxHeap2.Pop() << " ";
    }
    std::cout << std::endl;
}
