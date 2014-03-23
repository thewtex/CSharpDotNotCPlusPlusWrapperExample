#include "Class1Wrapper.h"

#pragma managed

#include <vcclr.h>
#include <msclr/marshal_cppstd.h>

#using "ClassLibrary1.dll"


using namespace ClassLibrary1;

class Class1WrapperImpl
{
public:
  Class1WrapperImpl()
    {
    this->Wrapped = gcnew Class1();
    }
  ~Class1WrapperImpl()
    {
    }

  int Add(int xx, int yy)
    {
    return this->Wrapped->Add(xx, yy);
    }
private:
  gcroot<Class1 ^> Wrapped;
};

#pragma unmanaged

Class1Wrapper
::Class1Wrapper():
  Impl( new Class1WrapperImpl() )
{
}

Class1Wrapper
::~Class1Wrapper()
{
  delete Impl;
}

int
Class1Wrapper
::Add(int xx, int yy)
{
  return this->Impl->Add(xx, yy);
}
