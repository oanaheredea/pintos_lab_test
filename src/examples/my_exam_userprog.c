#include <stdio.h>
#include <syscall.h>

int main(void)
{
	map_page_zero();
	int *buffer = 0;
	for (int i = 0; i < 1024/4; i+=4)
	{
		buffer[i] = 10;
	}
	for (int i = 0; i < 1024; i++)
		printf("%d ", buffer[i]);
	unmap_page_zero();
	for (int i = 0; i < 1024; i++)
		printf("%d ", buffer[i]);
	return 0;
}
