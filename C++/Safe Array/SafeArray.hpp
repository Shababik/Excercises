#include "InvalidSizeException.h"
#include "OutOfBoundsException.h"
#include "MemoryAllocationException.h"
#include <limits.h>


/*** consts ***/

const char * outOfBoundsExceptionMsg =
"Index is not within the range of the array.";
const char * invalidSizeExceptionMsg =
"Array size is illegal.";
const char * memoryAllocationExceptionMsg =
"Not enough memory.";

// template for SafeArray<T>
template <class T>
class SafeArray
{
public:
	// SafeArray<T> Constructor. 
	// Throws InvalidSizeException, MemoryAllocationException.
	SafeArray(int size);

	// Destructor
	~SafeArray() { delete[] this->data; }

	// Returns the SafeArray length
	int length();

	// Casting the SafeArray to a T pointer returns a pointer to data array
	operator T * () { return data; }

	// Returns a reference to the item at index.
	// Throws OutOfBoundsException.
	T & operator[] (int index);

	//  Supporting receiving pointer using syntax:
	//T * p = arr + offset;
	// Throws OutOfBoundsException.
	template <class T>
	friend T * operator+ (const SafeArray<T> & arr, int offset);

	// Supporting receiving pointer using syntax:
	// T * p = offset + arr;
	// Throws OutOfBoundsException.
	template <class T>
	friend T * operator+ (int offset, const SafeArray<T> & arr);

private:
	// array of T pointers
	T * data;
	// size of SafeArray
	int size;
	// max size of SafeArray
	static int const MAX_SIZE = INT_MAX;
};


// SafeArray<T> Constructor. 
// Throws InvalidSizeException, MemoryAllocationException.
template<class T>
SafeArray<T>::SafeArray(int size)
{
	// if size is invalid, throw InvalidSizeException
	if (size < 0 || size > MAX_SIZE - 1 )
	{
		throw InvalidSizeException(invalidSizeExceptionMsg);
	}

	// try to allocate size*sizeof(T+1) memory for array.
	// SafeArray[size] is always NULL, and is used as a stopping condition
	// for iterating over SafeArray using length(), when receiving a pointer.
	try
	{
		data = new T[size+1];
	}
	// if allocation fails, throw MemoryAllocationException
	catch (...)
	{
		throw MemoryAllocationException(memoryAllocationExceptionMsg);
	}

	// initializing array with NULL pointers
	for (int i = 0; i <= size; i++)
	{
		data[i] = NULL;
	}

	// initializing size field
	this->size = size;
}


// Returns the SafeArray length
template<class T>
int SafeArray<T>::length()
{
	return this->size;
}


// Returns a reference to the item at index.
// Throws OutOfBoundsException.
template <class T>
T & SafeArray<T>::operator[] (int index)
{
	if (index < 0 || index >= size)
	{
		throw OutOfBoundsException(outOfBoundsExceptionMsg);
	}
	return data[index];
}


// Supporting receiving pointer using syntax:
// T * p = arr + offset;
// Throws OutOfBoundsException.
template <class T>
T * operator+ (const SafeArray<T> & safeArray, int offset)
{
	if (offset < 0 || offset >= safeArray.size)
	{
		throw OutOfBoundsException(outOfBoundsExceptionMsg);
	}
	return safeArray.data + offset;
}


// Supporting receiving pointer using syntax:
// T * p = offset + arr;
// Throws OutOfBoundsException.
template <class T>
T * operator+ (int offset, const SafeArray<T> & safeArray)
{
	return safeArray.operator+(safeArray, offset);
}
