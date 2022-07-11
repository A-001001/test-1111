#include<process_copy.h>



void copy(const char*sfile,const char*dfile,int blocksize,int flags)
{

	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;


	int sfd=open(sfile,O_RDONLY);
	int dfd=open(dfile,O_RDWR|O_CREAT,0664);
	
	lseek(sfd,flags,SEEK_SET);
	lseek(dfd,flags,SEEK_SET);

	readlen=read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);
	close(sfd);
	close(dfd);



	return 0;
}
