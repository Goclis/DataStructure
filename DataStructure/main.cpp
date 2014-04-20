#include <iostream>
#include "sort.h"
#include "linearlist.h"
#include "listexception.h"
#include "chainlist.h"

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
    // test insert, 9, 8, 7, 6, ..., 1, 0
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

// unit test for ChainList
void TestChainList() {
    using namespace goclis_list;
    ChainList<int> chain;

    std::cout << "Before do some operations: " << std::endl;
    std::cout << "Length: " << chain.Length() << std::endl;
    std::cout << "IsEmpty(): " << chain.IsEmpty() << std::endl;
    chain.Output();

    std::cout << "Do some operations now... " << std::endl;
    // Insertion
    chain.Insert(0, 1);
    std::cout << "After Insert 1 at 0: " << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    chain.Insert(1, 2);
    std::cout << "After Insert 2 at 1: " << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    chain.Insert(0, 3);
    std::cout << "After Insert 3 at 0: " << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    chain.Insert(0, 4);
    std::cout << "After Insert 4 at 0: " << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    chain.Insert(2, 5);
    std::cout << "After Insert 5 at 2: " << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    try {
        int i = chain.Length();
        chain.Insert(i, 2);
        std::cout << "After Insert 2 at " << i << ": " << std::endl;
        chain.Output();
        std::cout << "Length: " << chain.Length() << std::endl;
    } catch (OutOfBoundException) {
        std::cout << "Test Insert OutOfBound Ok!" << std::endl;
    }
    try {
        chain.Insert(-1, 2);
    } catch (OutOfBoundException) {
        std::cout << "Test Insert OutOfBound Ok!" << std::endl;
    }
    
    // Search & Find
    std::cout << "Search 2: " << chain.Search(2) << std::endl;
    std::cout << "Saerch 100: " << chain.Search(100) << std::endl;
    int fe;
    chain.Find(0, fe);
    std::cout << "Find 0: " << fe << std::endl;
    chain.Find(chain.Length() - 1, fe);
    std::cout << "Find lenght-1 : " << fe << std::endl;
    try {
        chain.Find(100, fe);
    } catch (OutOfBoundException) {
        std::cout << "Test Find OutOfBound Ok!" << std::endl;
    }

    // Deletion
    int de;
    chain.Delete(0, de);
    std::cout << "After Delete element at 0: " << de << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    chain.Delete(3, de);
    std::cout << "After Delete element at 3: " << de << std::endl;
    chain.Output();
    std::cout << "Length: " << chain.Length() << std::endl;
    try {
        chain.Delete(-1, de);
    } catch (OutOfBoundException) {
        std::cout << "Test Delete OutOfBound Ok!" << std::endl;
    }
    try {
        chain.Delete(chain.Length(), de);
    } catch (OutOfBoundException) {
        std::cout << "Test Delete OutOfBound Ok!" << std::endl;
    }
}
int main(int argc, char **argv) {
    //TestLinearList();
    TestChainList();
}