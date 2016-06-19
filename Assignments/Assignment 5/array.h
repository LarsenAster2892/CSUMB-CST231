//********************************************************
// File Name   : Array.h  
// Author      : Clarence Mitchell
// Assignment  : Number 5
// Date Due    : July 31, 2003 (11:59 PM)
// Description : (array.h) Header file for Template class
//               Declaration and method definitions for a 
//               generic bounds-checked array class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************


#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <exception>

template <typename T>
class Array;

template <typename T>
std::ostream & operator<<(std::ostream &os, const Array<T> &a);

template <typename T>
class Array
{
  public:
    class ArrayIndexOutOfBoundsException : public std::exception
    {
      private:
        unsigned index_;             // out-of-bounds array index
        std::string error_message_;  // error message

      public:
        ArrayIndexOutOfBoundsException(unsigned index) :
          index_(index) {
          std::ostringstream oss;
          oss << "Array index " << index << " out of bounds";
          error_message_ = oss.str();
        }
        const char* what() { return error_message_.c_str(); }
    };


	class InvalidStateException : public std::exception
	{
		public:		
			InvalidStateException() : exception() {};
			const char * what() { return "Cannot compute average of zero-length array\n"; }
	};

  private:
    unsigned int size_;  // size of array
    T *array_;           // pointer to first array element

  public:
    Array();
    explicit Array(unsigned size, T default_value = 0);
    Array(const T *pa, unsigned size);
    Array(const Array &a);
    virtual ~Array();

    unsigned size() { return size_; }

    Array & operator=(const Array &a);
    T & operator[](unsigned index);
      // throw (Array::ArrayIndexOutOfBoundsException &);
    const T & operator[](unsigned index) const;
      // throw (Array::ArrayIndexOutOfBoundsException &);

	double average() const throw (Array::InvalidStateException &);

    friend std::ostream & operator<< <>(std::ostream &os, const Array &a);



};

template <typename T>
Array<T>::Array()
{
  size_ = 0;
  array_ = 0;
}

template <typename T>
Array<T>::Array(unsigned size, T default_value)
{
  size_ = size;
  array_ = new T[size_];
  for (unsigned i = 0; i < size_; i++)
    array_[i] = default_value;
}

template <typename T>
Array<T>::Array(const T *pa, unsigned size)
{
  size_ = size;
  array_ = new T[size_];
  for (unsigned i = 0; i < size_; i++)
    array_[i] = pa[i];
}

template <typename T>
Array<T>::Array(const Array &a)
{
  size_ = a.size_;
  array_ = new T[size_];
  for (unsigned i = 0; i < size_; i++)
    array_[i] = a.array_[i];
}

template <typename T>
Array<T>::~Array()
{
  delete[] array_;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array &a)
{
  if (&a == this) return *this;
  delete[] array_;
  size_ = a.size_;
  array_ = new T[size_];
  for (unsigned i = 0; i < size_; i++)
    array_[i] = a.array_[i];
  return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned index)
  // throw (Array::ArrayIndexOutOfBoundsException &)
{
  if (index < 0 || index >= size_)
    throw ArrayIndexOutOfBoundsException(index);
  return array_[index];
}

template <typename T>
const T & Array<T>::operator[](unsigned index) const
  // throw (Array::ArrayIndexOutOfBoundsException &)
{
  if (index < 0 || index >= size_)
    throw ArrayIndexOutOfBoundsException(index);
  return array_[index];
}

template <typename T>
double Array<T>::average() const throw (Array::InvalidStateException &)
{
  if (size_) {
    double sum = 0;
    for (unsigned i = 0; i < size_; i++)
      sum += array_[i];
    return sum / size_;
  }
  else {
	  throw InvalidStateException();
  }
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const Array<T> &a)
{
  os << '[';
  for (unsigned i = 0; i < a.size_; i++)
    os << (i ? ", " : "") << a.array_[i];
  os << ']';
  return os;
}

#endif

