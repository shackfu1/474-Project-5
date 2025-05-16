#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "image.h"

unsigned char *bread(int block_num, unsigned char *block){
	off_t offset = lseek(image_fd, 4096 * block_num, SEEK_SET);
	read(image_fd, block, 4096);
	return block;
	(void) offset;
}

void bwrite(int block_num, unsigned char *block){
	off_t offset = lseek(image_fd, 4096 * block_num, SEEK_SET);
	write(image_fd, block, 4096);
	(void) offset;
}