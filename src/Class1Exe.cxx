#pragma managed

#include <vcclr.h>
//#import "ClassLibrary1.tlb" raw_interfaces_only
#using "ClassLibrary1.dll"

using namespace ClassLibrary1;

int main( int argc, char * argv[] )
{
gcroot< Class1 ^ > class1 = gcnew Class1();
//Class1 ^ class1;
return 0;
}
