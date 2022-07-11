#include <process_copy.h>


int file_block (const char* sfile, int pronum) {
	/*open file and get size of file*/ 
	int fd = open(sfile, O_RDONLY);
	int fsize = lseek(fd, 0, SEEK_END);

	/*compute task quantity*/
	if (fsize % pronum == 0)
		return fsize / pronum;
	else 
		return fsize / pronum + 1;
}
