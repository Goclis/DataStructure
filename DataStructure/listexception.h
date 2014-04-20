/*
    Date: 2014/04/19
    Author: Goclis Yao
    Email: goclisyyh@gmail.com
    Description: 为链表提供的一系列异常
*/

#ifndef LIST_EXCEPTION_H_
#define LIST_EXCEPTION_H_

namespace goclis_list {
    // No memory 
    class NoMemoryException {
    public:
        NoMemoryException() {
            // std::cout << "No Memory" << std::endl;
        }
    };
    
    // Out of bound
    class OutOfBoundException {
    public:
        OutOfBoundException() {
            // std::cout << "Out Of Bound" << std::endl;
        }
    };
}

#endif // LIST_EXCEPTION_H_