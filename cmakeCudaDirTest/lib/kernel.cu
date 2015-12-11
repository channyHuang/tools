#include <stdio.h>
#include "kernel.h"


extern "C" void kernel()
{
	printf("hello world!");
}