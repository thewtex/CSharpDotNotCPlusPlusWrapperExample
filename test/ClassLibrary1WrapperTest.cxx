#include "Class1Wrapper.h"
#include <iostream>

int main( int argc, char * argv[] )
{
  Class1Wrapper class1;
  int result = class1.Add(4, 3);
  std::cout << "Result: " << result << std::endl;

  Class1Wrapper * class1Ptr = new Class1Wrapper();
  int ptr_result = class1Ptr->Add(2, 4);
  std::cout << "Pointer result: " << ptr_result << std::endl;
  delete class1Ptr;

  return 0;
}
