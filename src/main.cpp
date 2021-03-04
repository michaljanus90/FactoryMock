#include <iostream>

#include "Usage.hpp"


int main()
{
	src::Usage usg;
	usg.doSmth(10.7, 45.6);

	src::Usage usg2('M');
	usg2.doSmth(10.7, 45.6);
	
	return 0;
}
