/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** main.c
*/

#include "include/my.h"
#include <sys/sysinfo.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <utmp.h>

int main(void)
{
    struct sysinfo info;
    int key = 0;

    sysinfo(&info);
    initscr();
    timeout(3000);
    keypad(stdscr, TRUE);
    while (key != 27) {
        clear();
        display_first_line();
        display_second_line();
        display_line_four(&info);
        display_line_five();
        key = getch();
        refresh();
    }
    endwin();
    return 0;
}
