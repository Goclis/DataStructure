#include <iostream>
#include "sort.h"
#include "linearlist.h"
#include "listexception.h"

// unit test for SelectionSort
void TestSelectionSort() {
    int a[7] = {3, 1, 2, 5, 9, 100, -1};

    goclis_sort::SelectionSort<int>(a, 7);

    for (int i = 0; i < 7; i++) {
        std::cout << a[i] << ' ';
    }
}

// unit test for LinearList
void TestLinearList() {
    goclis_list::LinearList<int> shortlist(1);
    shortlist.Insert(0, 1);
    try {
        shortlist.Insert(0, 2); // test NoMemory
    } catch (goclis_list::NoMemoryException) {
        std::cout << "NoMemory test pass" << std::endl;
    }

    goclis_list::LinearList<int> list(10);
    // test insert, 0, 9, 8, 7, 6, ..., 1
    for (int i = 0; i < 10; ++i) {
        list.Insert(0, i);  
    }
    list.Output();

    // test search
    std::cout << "Search 3: " << list.Search(3) << std::endl;  

    // test find
    int fe;
    if (list.Find(2, fe)) { // valid index
        std::cout << "Find list(2) = " << fe << std::endl;
    }
    if (!list.Find(-1, fe)) { // invalid index
        std::cout << "Invalid index pass." << std::endl;
    }

    // test delete
    int de;
    list.Delete(0, de); // first element
    std::cout << "Deleted element: " << de << std::endl;
    std::cout << "After Deleted: ";
    list.Output();
    std::cout << "Length: " << list.Length() << std::endl;
    list.Delete(5, de); // middle element
    std::cout << "Deleted element: " << de << std::endl;
    std::cout << "After Deleted: ";
    list.Output();
    std::cout << "Length: " << list.Length() << std::endl;
    list.Delete(list.Length() - 1, de); // last element
    std::cout << "Deleted element: " << de << std::endl;
    std::cout << "After Deleted: ";
    list.Output();
    std::cout << "Length: " << list.Length() << std::endl;
    // test OutOfBound
    try {
        list.Delete(list.Length(), de);
    } catch (goclis_list::OutOfBoundException) {
        std::cout << "OutOfBound test pass." << std::endl;
    }
    try {
        list.Delete(-1, de);
    } catch (goclis_list::OutOfBoundException) {
        std::cout << "OutOfBound test pass again." << std::endl;
    }
}

int main(int argc, char **argv) {
    TestLinearList();
}