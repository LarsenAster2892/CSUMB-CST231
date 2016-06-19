// Declaration for a revised basic string class

#ifndef XSTRING2_H
#define XSTRING2_H

#include <iostream>

class XString
{
  private:
    static int xstring_id;    // counts number of XStrings constructed
    static int num_xstrings;  // counts number of active XStrings

    int id_;                  // string id
    size_t length_;           // string length
    char *str_;               // pointer to null-terminated char array

  public:
    XString(const char *str = "");
    XString(const XString &s);
	
    ~XString();

    XString & operator=(const XString &s);
    XString operator+(const XString &xs2) const;	
    XString operator+(char ch) const;
    XString operator+(const char *cs) const;    
	
    friend std::ostream & operator<<(std::ostream &os,
      const XString &s);
};



XString operator+(char ch, const XString &xs);
XString operator+(const char* cs, const XString &xs);
#endif

