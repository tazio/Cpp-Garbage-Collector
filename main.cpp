#include <iostream>

#include "library/utilities.hpp"
#include "library/smart_pointers.hpp"

class prova
{
	int a;
public:
	prova(int x):a(x) {}
};

using namespace gc;

//! @note Test file
int main(int argc, char **argv)
{
	smart_pointer<prova> c(43);
    
	return 0;
}
