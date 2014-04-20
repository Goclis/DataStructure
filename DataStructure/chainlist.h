/*
    Date: 2014/04/19
    Author: Goclis Yao
    Email: goclisyyh@gmail.com
    Description: Á´±í
*/

#ifndef CHAIN_LIST_H_
#define CHAIN_LIST_H_

namespace goclis_list {
    using namespace goclis_list;

    template <typename T>
    class ChainNode {
    public:
        T data;
        ChainNode<T> *link;
    };

    template <typename T>
    class ChainList {
    public:
        ChainList();
        ~ChainList();
        bool IsEmpty() const;
        int Length() const;
        bool Find(int k, T &x) const;
        int Search(const T &x) const;
        ChainList<T>& Delete(int k, T &x);
        ChainList<T>& Insert(int k, const T &x);
        void Output() const;

    private:
        ChainNode<T> *first;
    };
}

namespace goclis_list {
    using namespace goclis_list;

    template <typename T>
    ChainList<T>::ChainList() {
        first = NULL;
    }

    template <typename T>
    ChainList<T>::~ChainList() {
        ChainNode<T> *next;

        while (first) {
            next = first->link;
            delete first;
            first = next;
        }
    }

    template <typename T>
    bool ChainList<T>::IsEmpty() const {
        return first == NULL;
    }

    template <typename T>
    int ChainList<T>::Length() const {
        int length = 0;
        ChainNode<T> *next = first;
        while (next) {
            length += 1;
            next = next->link;
        }

        return length;
    }

    template <typename T>
    bool ChainList<T>::Find(int k, T &x) const {
        if (k < 0) {
            return false;
        }

        ChainNode<T> *current = first;
        int index = 0;
        while (index < k && current) {
            current = current->link;
            index += 1;
        }
        if (current) {
            x = current->data;
            return true;
        }

        return false;
    }

    template <typename T>
    int ChainList<T>::Search(const T &x) const {
        ChainNode<T> *current = first;
        int index = 0;
        while (current && current->data != x) {
            index += 1;
            current = current->link;
        }
        if (current) {
            return index;
        }

        return -1;
    }

    template <typename T>
    void ChainList<T>::Output() const {
        using namespace std;
        ChainNode<T> *current = first;
        while (current) {
            cout << current->data << " ";
            current = current->link;
        }
        cout << endl;
    }

    template <typename T>
    ChainList<T>& ChainList<T>::Delete(int k, T &x) {
        if (k < 0 || !first) {
            throw OutOfBoundException();
        }

        ChainNode<T> *node_to_delete = first;
        if (k == 0) {
            first = first->link;
        } else {
            ChainNode<T> *node_forward_delete = first; // hold the (k-1)th node
            // find the (k-1)th node
            for (int index = 0; index < k - 1 && node_forward_delete; ++index) {
                node_forward_delete = node_forward_delete->link;
            }
            
            if (!(node_forward_delete && node_forward_delete->link)) {
                throw OutOfBoundException();
            }
            node_to_delete = node_forward_delete->link;
            node_forward_delete->link = node_to_delete->link;
        }

        x = node_to_delete->data;
        delete node_to_delete;
        return *this;
    }

    template <typename T>
    ChainList<T>& ChainList<T>::Insert(int k, const T &x) {
        if (k < 0) {
            throw OutOfBoundException();
        }
        if (k == 0) {
            ChainNode<T> *node_to_insert = new ChainNode<T>();
            node_to_insert->link = first;
            node_to_insert->data = x;
            first = node_to_insert;
        } else {
            ChainNode<T> *node_before_insert = first;
            for (int index = 0; index < k - 1 && node_before_insert; ++index) {
                node_before_insert = node_before_insert->link;
            }
            
            if (node_before_insert) {
                ChainNode<T> *node_to_insert = new ChainNode<T>();
                node_to_insert->data = x;
                node_to_insert->link = node_before_insert->link;
                node_before_insert->link = node_to_insert;
            } else {
                throw OutOfBoundException();
            }  
        }

        return *this;
    }
}

#endif CHAIN_LIST_H_

