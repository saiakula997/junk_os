all:
	gcc *.c -o junk_os -g -DINCLUDE_TEST_SUIT=1

clean: 
	rm -rf junk_os
