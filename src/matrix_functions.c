#include "main.h"

//Random number generator
int rand_num(int min, int max)
{
    return min + rand()%(max +1 - min);
} 

void create_colum(int max, t_colum *colum_arr[]) {
    for (int i = 0; i < max; ++i) {
        colum_arr[i] = (t_colum *)malloc(sizeof(t_colum)); 
        if(colum_arr[i] == NULL)
            exit(1);
        
        colum_arr[i] -> start = -1;
        colum_arr[i] -> end = -1;
        colum_arr[i] -> speed = rand_num(0, 2);
        colum_arr[i] -> last_char = ' ';
    }
}

//Increment the start point of the rain
void rain_fall(int index, int max_y, t_colum *colum_arr)
{
    if(colum_arr -> start < 0)
        (colum_arr -> start) += (rand_num(0, 1000) > 985) ? 1 : 0; // randomize rain start
    else if(colum_arr -> start < max_y) {
        if(colum_arr -> count < colum_arr -> speed) {
            colum_arr -> count++;
            return;
        }
        attron(COLOR_PAIR(1));
        mvwaddch(stdscr, colum_arr -> start -1, index, colum_arr -> last_char );
        attron(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvwaddch(stdscr, colum_arr -> start, index, colum_arr -> last_char = rand_num(MIN_RAND, MAX_RAND));
        attron(COLOR_PAIR(2));

        (colum_arr -> start)++; //next coordinate
        colum_arr -> count = 0;
    }
    else {
        attron(COLOR_PAIR(1));
        mvwaddch(stdscr, colum_arr -> start - 1, index, colum_arr -> last_char );
        attron(COLOR_PAIR(1));
        colum_arr -> start = -1; // end of falling
        colum_arr -> speed = rand_num(0, 2);
        colum_arr -> count = 0;
    }

    if(colum_arr -> end < 0 && (MOD((colum_arr -> start) - (colum_arr -> end)) > 4  || (colum_arr -> start) == (colum_arr -> end)))
        (colum_arr -> end) += (rand_num(0, 1000) > 920) ? 1 : 0; // randomize rain end
    else if(colum_arr -> end  < max_y && colum_arr -> end  != -1) {
        mvwaddch(stdscr, colum_arr -> end, index, ' ');
        (colum_arr -> end)++; //next coordinate
    }
    else {
        colum_arr -> end  = -1; // end of falling
    }
}

void print_str(int *exit/*, char **str_arr*/)
{
    // for(unsigned int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]) && *exit; ++i)
    // {
    //     for(int index = 0; index < str_len(str_arr[index]) && *exit; ++index) {
    //         mvwaddch(stdscr, 4, 4 + index, *str_arr[index]); 
    //         refresh();
    //         if(getch() == 'q') {
    //             *exit = 0;
    //             break;
    //         }
    //     }
    //     sleep(1);
    // }
    char phrases1[] = "Wake up , Neo..";
    char phrases2[] = "The matrix has you..."; 
    char phrases3[] = "Follow the white rebbit";
    char phrases4[] = "Knock, knock Neo";
    attron(COLOR_PAIR(1));
    for(int index = 0; index < str_len(phrases1) && *exit; ++index) {
        mvwaddch(stdscr, 4, 4 + index, phrases1[index]); 
        refresh();
        if(getch() == 'q')
            *exit = 0;
    }
    sleep(1);
    clear();
    for(int index = 0; index < str_len(phrases2) && *exit; ++index) {
        mvwaddch(stdscr, 4, 4 + index, phrases2[index]); 
        refresh();
        if(getch() == 'q')
            *exit = 0;
    }
    sleep(1);  
    clear();
    for(int index = 0; index < str_len(phrases3) && *exit; ++index) {
        mvwaddch(stdscr, 4, 4 + index, phrases3[index]); 
        refresh();
        if(getch() == 'q')
            *exit = 0;
    }
    clear();
    sleep(1);
    for(int index = 0; index < str_len(phrases4) && *exit; ++index) {
        mvwaddch(stdscr, 4, 4 + index, phrases4[index]); 
        refresh();
        if(getch() == 'q')
            *exit = 0;
    }
    sleep(1);
    attron(COLOR_PAIR(1));
    clear();
}

int str_len(const char *s) {
    int len = 0;
    
    while (s[len] != '\0')
        ++len;

    return len;
}
