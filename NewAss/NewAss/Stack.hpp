// 1

#ifndef STACK_H
#define STACK_H

template <typename Object>
class Stack {
    
    private:
        int SizeOfStack, CapacityOfStack;
        Object * Stackobjects;
        void resizeTheStack(int newSize);
        void reserveTheStack(int newCapacity);
    
    public:
        Stack();
        ~Stack();
        void Stackpush(const Object & x);// insert an element at the top
        void Stackpop( );// erase the element at the top
        const Object & Attop() const;// returns the element at the top
        Object & Attop();
        bool Stackempty( ) const;
        int Stacksize( ) const;
        int Stackcapacity( ) const;
    

};

//#include "../src/Stack.cpp"
#endif
