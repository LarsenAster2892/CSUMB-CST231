// Method definitions for the revised XString class

#include <cstring>
#include "xstring2.h"

int XString::num_xstrings = 0;
int XString::xstring_id = 1;

XString::XString(const char *str)
{
  num_xstrings++;

  id_ = xstring_id++;
  length_ = strlen(str);
  if ((str_ = new char[length_ + 1]) != 0) {
    strcpy(str_, str);
    std::cout << "XString #" << id_
      << " [" << str_ << "] constructed; "
      << num_xstrings << " XString(s) total"
      << std::endl;
  }
  else {
    std::cerr << "XString #" << id_
      << " constructor failed: Out of memory; "
      << num_xstrings << " XString(s) total"
      << std::endl;
    length_ = 0;
    str_ = 0;
  }
}

XString::XString(const XString &s)
{
  num_xstrings++;

  id_ = xstring_id++;
  length_ = s.length_;
  if ((str_ = new char[length_ + 1]) != 0) {
    strcpy(str_, s.str_);
    std::cout << "XString #" << id_
      << " [" << str_ << "] copy constructed; "
      << num_xstrings << " XString(s) total"
      << std::endl;
  }
  else {
    std::cerr << "XString #" << id_
      << " copy constructor failed: Out of memory; "
      << num_xstrings << " XString(s) total"
      << std::endl;
    length_ = 0;
    str_ = 0;
  }
}

XString::~XString()
{
  std::cout << "XString #" << id_ << " [" << str_
    << "] destructed; " << --num_xstrings
    << " XString(s) remaining" << std::endl;
  delete[] str_;
}

XString & XString::operator=(const XString &s)
{
  if (&s != this) {
    delete[] str_;
    length_ = s.length_;
    if ((str_ = new char[length_ + 1]) != 0) {
      strcpy(str_, s.str_);
      std::cout << "XString #" << id_ << " assigned [" << str_ << ']'
        << std::endl;
    }
    else {
      std::cerr << "XString #" << id_ << " assignment failed: "
        "Out of memory" << std::endl;
      length_ = 0;
      str_ = 0;
    }
  }
  return (*this);
}

std::ostream & operator<<(std::ostream &os, const XString &s)
{
  os << (s.str_ ? s.str_ : "null");
  return os;
}

XString  XString::operator+(const char* &cs) const
{
  int csLen = strlen(cs);
  char * newstr = new char[length_ + cslen + 1];
   strcpy(newstr, str_);
   strcat(newstr, cs);
   XString tmpRtn(newstr);
   delete [] newstr;
 return XString(tmpRtn);	
}