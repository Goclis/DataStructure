/*
    Date: 2014/04/19
    Author: Goclis Yao
    Email: goclisyyh@gmail.com
    Description: ÏßÐÔ±í
*/

#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

#include <iostream>
#include "listexception.h"

namespace goclis_list {
    /*
        LinearList implemented by dynamic array,
        position from 0 to (length - 1), the same to *th
    */
    template <typename T>
    class LinearList {
    public:
        LinearList(int max_size = 0); // Constructor
        ~LinearList(); // Destructor
        bool IsEmpty() const; // Is list empty
        int Length() const; // return the length of list
        bool Find(int k, T &x) const; // find the kth element, start from 0
        int Search(const T &x) const; // return the position of element x
        LinearList<T>& Delete(int k, T &x); // Delete the kth element and set x
        LinearList<T>& Insert(int k, const T &x); // Insert the element x as the kth element
        void Output() const; // Print list
        
    private:
        int length;
        int max_size;
        T *elements;
    };
}

namespace goclis_list {
    // Constructor, empty list by default
    template <typename T>
    LinearList<T>::LinearList(int max_list_size = 0) {
        max_size = max_list_size >= 0 ? max_list_size : 0;
        elements = new T[max_size];
        length = 0;
    }

    // Destructor, release the memory of element
    template <typename T>
    LinearList<T>::~LinearList() {
        if (elements != NULL) {
            delete [] elements;
        }
    }

    // Return true if list is empty
    template <typename T>
    bool LinearList<T>::IsEmpty() const {
        return length == 0;
    }

    // Return the length of list
    template <typename T>
    int LinearList<T>::Length() const {
        return length;
    }

    // Find the kth element, start from 0
    template <typename T>
    bool LinearList<T>::Find(int k, T &x) const {
        if (k < 0 || k >= length - 1) {
            return false;
        }

        x = elements[k];
        return true;
    }

    // Return the position of element x, -1 if not exist,
    // position start from 0
    template <typename T>
    int LinearList<T>::Search(const T &x) const {
        for (int i = 0; i < length; ++i) {
            if (elements[i] == x) {
                return i;
            }
        }

        return -1;
    }

    // Delete the kth element, and set x
    // return NULL if out of bound,
    // else return the reference of the new list (*this)
    template <typename T>
    LinearList<T>& LinearList<T>::Delete(int k, T &x) {
        if (k < 0 || k > length - 1) {
            throw OutOfBoundException(); // out of bound
        }

        x = elements[k];

        // move the k+1, ..., length-1 forward
        for (int i = k + 1; i < length; ++i) {
            elements[i - 1] = elements[i];
        }

        length -= 1;

        return *this;
    }

    // Insert x at position k,
    // allow k == length, means append
    // return NULL if k out of bound or list is full
    // else return the reference of the new list (*this)
    template <typename T>
    LinearList<T>& LinearList<T>::Insert(int k, const T &x) {
        if (k < 0 || k > length) {
            throw OutOfBoundException(); // out of bound
        }

        if (length == max_size) {
            throw NoMemoryException(); // no memory
        }

        // move k, k + 1, ..., length - 1 backwards
        for (int i = length - 1; i >= k; --i) {
            elements[i + 1] = elements[i];
        }
        elements[k] = x;        
        length += 1;

        return *this;
    }

    // Print all elements
    template <typename T>
    void LinearList<T>::Output() const {
        for (int i = 0; i < length; ++i) {
            std::cout << elements[i] << " ";
        }

        std::cout << std::endl;
    }
}

#endif // LINEAR_LIST_H_