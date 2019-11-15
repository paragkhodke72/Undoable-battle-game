template <typename Object>
void Stack<Object>::pushStack(const Object & v)  {
    Node* newNode = new Node(); // create new vertex newNode from item v
    newNode->data = v;
    newNode->next = head; // link this new vertex to the (old) head vertex
    head = newNode; // the new vertex becomes the new head
    theSize++;
}

template <typename Object>
const Object & Stack<Object>::top() const {
    if (this->empty())
        throw "No more data in the stack to pop";
    return get(0)->data;
}

template <typename Object>
Stack<Object>::~Stack() {
    while(not this->emptyStack())
        this->popStack();
    cout<<"\n\nOpps.. Sorry you have used all your health while attatcking and now you are out of health !!";
}

template <typename Object>
Object & Stack<Object>::top()  {
    if (this->emptyStack())
        throw "\n\nYou both are healthy now.. kindly look at the Respected health ";

    return get(0)->data;
}


template <typename Object>
void Stack<Object>::popStack()  {
    if (this->emptyStack()) // avoid crashing when SLL is empty
        throw "\n\nOho !! Now No More health !! Kindly Please try again with another battle";
    Node* temp = head; // so we can delete it later
    head = head->next; // book keeping, update the head 
    theSize--;
    delete temp; // which is the old head
}


template <typename Object>
bool Stack<Object>::emptyStack() {
    return theSize == 0;
}

template <typename Object>
typename Stack<Object>::Node* Stack<Object>::get(int i) { // returns the vertex
    Node* ptr = head; // we have to start from head
    for (int k = 0; k < i; k++) // advance forward i time(s)
        ptr = ptr->next; // the pointers are pointing to the higher index
    return ptr;
}

template <typename Object>
int Stack<Object>::sizeofStack() const  {
    return theSize;
}

template <typename Object>
Stack<Object>::Stack() : theSize(0), head(nullptr) {
}
