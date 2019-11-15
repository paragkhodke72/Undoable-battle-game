template <typename nameOfObject>
  Stack<nameOfObject>::Stack() : theSize(0), theCapacity(16) {
    nameOfObjects = new nameOfObject[ theCapacity ];
  }


template <typename nameOfObject>
  Stack<nameOfObject>::~Stack() {
    delete[] nameOfObjects;
  }


template <typename nameOfObject>
  bool Stack<nameOfObject>::empty( ) const {
    return size( ) == 0; 
  }


template <typename nameOfObject>
  int Stack<nameOfObject>::size( ) const {
    return theSize; 
  }


template <typename nameOfObject>
  int Stack<nameOfObject>::capacity( ) const {
    return theCapacity; 
  }


template <typename nameOfObject>
  void Stack<nameOfObject>::push( const nameOfObject & x ) {
    if( theSize == theCapacity )
        reserve( 2 * theCapacity + 1 );
    nameOfObjects[ theSize++ ] = x;
  }


template <typename nameOfObject>
  void Stack<nameOfObject>::pop() {
    if(empty())
        throw "stack is empty";
    theSize--;
  }


template <typename nameOfObject>
  nameOfObject & Stack<nameOfObject>::top()  {
    if (empty())
        throw "stack is empty";
    
    return nameOfObjects[theSize - 1];
        
  }

template <typename nameOfObject>
  void Stack<nameOfObject>::resize(int newSize) {
    if( newSize > theCapacity )
        reserve( newSize * 2 );
    theSize = newSize;
  }



template <typename nameOfObject>
  void Stack<nameOfObject>::reserve(int NC) {
    nameOfObject *oldArray = nameOfObjects;

    int num = NC < theSize ? NC : theSize;
    NC += 16;
    nameOfObjects = new nameOfObject[ newCapacity ];
    
    for( int k = 0; k < num; k++ )
        nameOfObjects[ k ] = oldArray[ k ];

    theSize = num;
    theCapacity = NC;

    delete[] oldArray;
}
