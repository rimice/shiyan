#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include "ex02_cmd.h"

int main(void)
{
	char buf[20];
	int fd;
        int ret;
	fd = open("/dev/ex02", O_RDWR);
	if(fd < 0)
	{
		printf("open is error\n");
		return -1;
	}

	//read(fd, buf, 10);
	//printf("<read>buf is [%s]\n", buf);
	write(fd, "Tenix Xu", 10);//写入
      
	read(fd, buf, 10);//读出
        printf("buf is [%s]\n", buf);
        ioctl(fd,ex02_CLEAR,0);  //再清空 
	close(fd);
	return 0;
}


