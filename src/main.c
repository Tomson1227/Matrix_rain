#include "main.h"

int main()
{
    int MAX_Y;
    int MAX_X;
    int exit = 1;
    //char *phrases[] = {"Wake up , Neo..", "The matrix has you...", "Follow the white rebbit", "Knock, knock Neo", NULL};

    //Grafical part
    initscr(); // Переход в curses-режим
    start_color();   //«цветовой движок»
    noecho();
    curs_set(FALSE); //Cursor off
    getmaxyx(stdscr, MAX_Y, MAX_X); //get screen parametrs
    halfdelay(1);
    
    //Set different language
    // setlocale(LC_ALL, 'Rus');
    // if (setlocale(LC_ALL, "") == NULL) {
    //     puts("Unable to set locale");
    // }

    //init structire array
    t_colum *colum_arr[MAX_X];   
    create_colum(MAX_X, colum_arr);

    //Initialies color paterns
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    
    //print string text
    print_str(&exit/*, phrases*/);
    // sleep(1);

    //infinity cicle
    while(exit) {
        for(int i = 0; i < MAX_X; ++i) {
            rain_fall( i, MAX_Y, colum_arr[i]);
        }
        refresh();
        if(getch() == 'q')
            exit = 0;
    }

    clear(); //Очистка екрана
    endwin();    // Выход из curses-режима. Обязательная команда.
    return 0;
}

//Generate n-long random content string

    /*******************************************************/
    /*******************UNCURSES_COMMANDS*******************/
    /*******************************************************/
    // initscr();    // Переход в curses-режим. Обязательная команда.
    
    // endwin();    // Выход из curses-режима. Обязательная команда.
    
    // start_color();   //«цветовой движок»
    // (COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE)
    // //move (row, col);            //смещаем курсор в ряд row, колонку col
    // printw("Hello world!\n");  // Отображение приветствия в буфер
    // refresh();                   // Вывод приветствия на настоящий экран
    // getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    // mvaddch(row,col,ch); //смещаем курсор в ряд row, колонку col и печатает символ
    // getmaxyx( stdscr, MaxY, MaxX ) //размер екрана
    /*******************************************************/
    /*******************************************************/

