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
    int key = 0;

    initscr();
    keypad(stdscr, TRUE);
    while (key != 27) {
        clear();
        display_first_line();
        key = getch();
        refresh();
    }
    endwin();
    return 0;
}
