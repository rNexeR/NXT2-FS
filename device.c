#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "device.h"

static const char *device_path;
static FILE *f;

int readSB(const char *path){
	printf("path %s\n",device_path );
	int fd = open(path, O_RDONLY);
	char but[1024];

	read(fd, but, 1024);  
  	read(fd, &es, sizeof(struct s_superblock));
  	/*printf("size of int %d size of int short %d\n",sizeof(int),sizeof(short int) );
  	printf("Size of super %d\n", sizeof(struct s_superblock));*/
  	printf("Magic %d\n", es.s_magic);
  	size_of_block = 1024 << es.s_log_block_size;
  	printf("Size of block %d\n", size_of_block);
  	if(es.s_log_frag_size >= 0){
  		size_of_fragment = 1024 << es.s_log_frag_size;
  	}else{
  		size_of_fragment = 1024 >> -es.s_log_frag_size;
  	}
  	printf("Size of fragment %d\n", size_of_fragment);

  	close(fd);

  	return es.s_magic == 61267 ? 0 : -1;
}

int device_open(const char *path) {
    device_path = path;
    f = fopen(path, "r+");

    int status = readSB(path);
	
    return (f != NULL && status == 0);
}

void device_close(){
    fflush(f);
    fclose(f);
}

void device_flush(){
    fflush(f);
}
