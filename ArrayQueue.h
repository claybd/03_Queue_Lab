//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/06/26
#include "Queue.h"

template <class T>
class ArrayQueue : public Queue <T> {
 public:
  //See Queue.h for documentation of these methods

  //This class MUST use the "circular" array concept,
  // so if I do add, remove, add, remove, add, remove ...
  // even if I do it 10000000 times, your array should not grow.
  // The array should never grow unless numItems == backingArraySize
  void add(T toAdd);
  T remove();
  unsigned int getNumItems();

  //Initialize all private member variables.
  // You initial backing array should be length 10. Allocate it
  // using "new"
  ArrayQueue();
  //Delete any dynamically allocated memory. If you are deleting
  // an array, be sure to use "delete[]" instead of "delete"
  virtual ~ArrayQueue();

 private:
  //If the backing array is too small, you may call this function.
  // It should create a new backing array twice as big as the old one,
  // and copy over the old data into the new array. It should finish
  // off by calling delete[] on the old backing array
  void grow();

  //Pointer to the array that we are using to store the queue
  T* backingArray;
  
  //The index in T where the front of the queue is.
  unsigned int front;
  //Number of items in the queue
  unsigned int numItems;

  //Number of spaces in the array pointed to by backingArray
  unsigned int backingArraySize;
};

#include "ArrayQueue.ipp"