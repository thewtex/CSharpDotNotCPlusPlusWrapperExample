#ifndef _Class1Wrapper_h
#define _Class1Wrapper_h

#include <string>
#include "ClassLibrary1Wrapper_Export.h"

#pragma unmanaged

class Class1WrapperImpl;

class ClassLibrary1Wrapper_EXPORT Class1Wrapper
{
public:
  Class1Wrapper();
  ~Class1Wrapper();

  int Add(int xx, int yy);

private:
  Class1WrapperImpl * Impl;
};


#endif // _Class1Wrapper_h
