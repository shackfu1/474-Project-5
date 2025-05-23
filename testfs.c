#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "image.h"
#include "block.h"
#include "ctest.h"

#ifdef CTEST_ENABLE

void test_image(void)
{
	remove("testfile");
    CTEST_ASSERT(image_open("testfile", 0), "test to make sure opening a file works");
    bool exists = false;
	if (access("testfile", F_OK) == 0) {
	    exists = true;
	}
    CTEST_ASSERT(exists, "test to make sure that after opening a file it exists");
    CTEST_ASSERT(image_close(), "test to make sure closing a file works");
}

void test_block(void){
	image_open("testfile2", 0);
	unsigned char *message = (unsigned char *)"test message";
	unsigned char buffer[4096];
	bwrite(10, message);
	bread(10,buffer);
	CTEST_ASSERT(strcmp((const char *)buffer, (const char *)message) == 0, "writing a message to a block and then reading the block lets you retrieve the message");
}

int main(void)
{
    CTEST_VERBOSE(1);

    test_image();

    test_block();

    CTEST_RESULTS();

    CTEST_EXIT();
}

#else

int main(){
	image_open("filename", 0);
	unsigned char *message = (unsigned char *)"test message";
	unsigned char buffer[4096];
	printf("%s\n", message);
	printf("%li\n", strlen((const char *)buffer));
	bwrite(10, message);
	bread(10, buffer);
	printf("%s\n", buffer);
	printf("%li\n", strlen((const char *)buffer));
	image_close();
}

#endif