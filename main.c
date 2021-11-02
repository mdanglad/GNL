#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	get_next_line(open("get_next_line.h", O_RDONLY));
	return 0;
}
