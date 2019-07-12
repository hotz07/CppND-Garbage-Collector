    // This class defines an element that is stored
// in the garbage collection information list.
//
template <class T>
class PtrDetails
{
  public:
    unsigned refcount; // current reference count
    T *memPtr;         // pointer to allocated memory
    /* isArray is true if memPtr points
to an allocated array. It is false
otherwise. */
    bool isArray; // true if pointing to array
    /* If memPtr is pointing to an allocated
array, then arraySize contains its size */
    unsigned arraySize; // size of array
    // Here, mPtr points to the allocated memory.
    // If this is an array, then size specifies
    // the size of the array.

        // TODO: Implement PtrDetails
    PtrDetails(T *m_ptr, unsigned size = 0)
    {
        refcount = 1;
        memPtr = m_ptr;
        if (size != 0) isArray = true;
        else isArray = false;

        arraySize = size;
    }
};
// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
        // TODO: Implement operator==      
        return (obj_1.memPtr == obj_2.memPtr);
}


// Copy constructor of Pointer class
template< class T, int size>
Pointer<T,size>::Pointer(const Pointer &ob){
    typename std::list<PtrDetails<T> >::iterator p;
    p = findPtrInfo(ob.addr);
    p->refcount++; // increment ref count
    addr = ob.addr;
    arraySize = ob.arraySize;
    if (arraySize > 0)
        isArray = true;
    else
        isArray = false;
}

// Overload assignment of Pointer to Pointer. (i.e ptr = ptr)
template <class T, int size>
Pointer<T, size> &Pointer<T, size>::operator=(Pointer &rv){
    typename std::list<PtrDetails<T> >::iterator p;
    // First, decrement the reference count
    // for the memory currently being pointed to.
    p = findPtrInfo(addr);
    p->refcount--;
    // Next, increment the reference count of
    // the new address.
    p = findPtrInfo(rv.addr);
    p->refcount++;  // increment ref count
    addr = rv.addr; // store the address.
    return rv;
}