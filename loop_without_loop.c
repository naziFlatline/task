#include <stdio.h>

int static counter = 1;

int outPut();

int main(int agrc, char *argv[])
{
	outPut();
	return 0;
}

int outPut()
{
	if(counter != 101)
	{
		printf("%d\n",counter);
		counter++;
		outPut();
	}
	return 0;
}
