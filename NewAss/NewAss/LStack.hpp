#ifndef LSTACK_H
#define LSTACK_H

template <typename Object>
class Stack  {
    private:
		struct Node {
			Object data;
			Node *next;
			Node(const Object & d = Object(), Node *n = nullptr) : data(d), next(n) {
			}
		};
    
    private:
        int theSize;
        Node* head;
        Node* get(int i);// returns the element i positions after head node

    public:
        Stack();
        ~Stack();
        void pushStack(const Object & v);// insert an element at the top
        void popStack();// erase the element at the top
        const Object & top() const;// returns the element at the top
        Object & top();
        bool emptyStack();// check if the stack is empty
        int sizeofStack() const; // returns the number of elements

};

#include "LStack.cpp"
#endif
