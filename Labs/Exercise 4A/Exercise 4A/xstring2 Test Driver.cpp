// Driver for exercising the XString class

#include <iostream>
#include "xstring2.h"

void pass_by_reference(XString &s);
void pass_by_value(XString s);

int main()
{
  XString s1("First string");
  XString s2("Second string");
  XString s3("Third string");
  XString s4("Fourth string");
  std::cout << std::endl;

  std::cout << "XStrings created:" << std::endl;
  std::cout << "s1: [" << s1 << ']' << std::endl;
  std::cout << "s2: [" << s2 << ']' << std::endl;
  std::cout << "s3: [" << s3 << ']' << std::endl;
  std::cout << "s4: [" << s4 << ']' << std::endl;
  std::cout << std::endl;

  std::cout << "Calling pass_by_reference(s1)..." << std::endl;
  pass_by_reference(s1);
  std::cout << "s1: [" << s1 << ']' << std::endl;
  std::cout << std::endl;

  std::cout << "Calling pass_by_value(s2)..." << std::endl;
  pass_by_value(s2);
  std::cout << "s2: [" << s2 << ']' << std::endl;
  std::cout << std::endl;

  std::cout << "Initializing s5 with s3..." << std::endl;
  XString s5 = s3;
  std::cout << "s3: [" << s3 << ']' << std::endl;
  std::cout << "s5: [" << s5 << ']' << std::endl;
  std::cout << std::endl;

  std::cout << "Creating s6..." << std::endl;
  XString s6;
  std::cout << "s6: [" << s6 << ']' << std::endl;
  std::cout << std::endl;

  std::cout << "Assigning s4 to s6..." << std::endl;
  s6 = s4;
  std::cout << "s4: [" << s4 << ']' << std::endl;
  std::cout << "s6: [" << s6 << ']' << std::endl;
  std::cout << std::endl;

  return 0;
}

void pass_by_reference(XString &s)
{
  std::cout << "pass_by_reference with ["
    << s << ']' << std::endl;
}

void pass_by_value(XString s)
{
  std::cout << "pass_by_value with ["
    << s << ']' << std::endl;
}

