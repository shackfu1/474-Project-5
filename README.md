# File System

## Building

Command line:

* `make` to build. An executable called `testfs` will be produced.
* 'make test' to build and run the executable immediately.
* `make clean` to clean up all build products except the executable and the static library.
* `make pristine` to clean up all build products entirely.


## Files

* `testfs.c`: The main code for testing the file system
* `image.c`: Code that describes functions for the file system image
* `block.c`: Code that describes functions for the data blocks


## Data

Image files can be opened and are used to store blocks of data. Unsigned char arrays are used as buffers for the data.


## Functions

testfs - 
* 'main()': (referring to the main inside the ctest if block, the other main() is unused) Runs the ctest tests to test the file system
  * 'test_image()': Tests to make sure image functions work
  * 'test_block()': Tests to make sure block functions work

block.c - 
* 'bread()': Reads from a block at a specified block number and returns the data
* 'bwrite()': Writes data to a block at a specified block number

image.c - 
* 'image_open': Opens an image file with a specified name, optionally truncated
* 'image_close': Closes the most recently opened image file

## Notes

* None