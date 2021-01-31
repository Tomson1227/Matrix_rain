FLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic
CC = clang
VAR_C = main.c matrix_functions.c
VAR_O = main.o matrix_functions.o
LN = -lncurses
all: install clean

uninstall: rm_obj clean 
	
reinstall: rm_obj clean install
	
clean:
	rm -rf *.c 
	rm -rf *.h
	rm -rf *.o
	
install: 
	cp src/*.c .
	cp inc/*.h .
	mkdir -p obj
	$(CC) $(FLAG) -c $(VAR_C)
	$(CC) $(FLAG) $(VAR_O) -o matrix_rain $(LN)
	mv *.o obj
	
rm_obj:
	rm -drf obj


	
	

