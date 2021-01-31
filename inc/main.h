#ifndef MAIN_H
#define MAIN_H

//includes
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <locale.h>
// #include “stdafx.h”
// #include <conio.h>
//#include <setlocale.h>

//definition
#define MIN_RAND 33
#define MAX_RAND 126
#define DELAY 100000
#define MOD(x) (x * ((x > 0) ? 1 : -1))

//structuse
typedef struct s_colum {
    int start;
    int end;
    int speed;
    char last_char;
    int count;
}              t_colum;

//Functions prototypes
int str_len(const char *s);
int rand_num(int min, int max);
void print_str(int *exit/*, char **str_arr*/);
void create_colum(int max, t_colum *colum_arr[]);
void rain_fall(int index, int max_y, t_colum *colum_arr);

#endif /* MAIN_H */
