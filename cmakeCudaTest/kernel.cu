#include <stdio.h>
#include "kernal.h"


extern "C" void kernel()
{
	printf("hello world!");
}