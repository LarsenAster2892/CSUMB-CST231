//********************************************************
// File Name   : Array.h  
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : July 24, 2003 (11:59 PM)
// Description : (arraye.h) Header file for Template class
//               Declaration and method definitions for a 
//               generic bounds-checked array class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>


#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array;

template <typename T>
std::ostream & operator<<(std::ostream &os, const Array<T> &a);

template <class T>
class Array
{
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
	double sum() const;

    Array & operator=(const Array &a);
    T & operator[](unsigned index);
    const T & operator[](unsigned index) const;

    double average() const;

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
{
  if (index < 0 || index >= size_) {
    std::cout << "Bad array index" << std::endl;
    exit(1);
  }
  return array_[index];
}

template <typename T>
const T & Array<T>::operator[](unsigned index) const
{
  if (index < 0 || index >= size_) {
    std::cout << "Bad array index" << std::endl;
    exit(1);
  }
  return array_[index];
}
//
//  --- included sum member function
//
template <typename T>
double Array<T>::sum() const
{
  if (size_) {
    double sum = 0;
    for (unsigned i = 0; i < size_; i++)
      sum += array_[i];
    return sum;
  }
  else {
    std::cout << "Cannot compute sum of zero-length array"
      << std::endl;
    return 0;
  }
}
template <typename T>
double Array<T>::average() const
{
  if (size_) {
    return sum() / size_;
  }
  else {
    std::cout << "Cannot compute average of zero-length array"
      << std::endl;
    return 0;
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

