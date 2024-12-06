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

void display_things(struct sysinfo *info)
{
    display_first_line();
    display_second_line();
    display_line_four(info);
    display_line_five();
    display_files_executing();
}

int main(void)
{
    struct sysinfo info;
    int key = 0;

    sysinfo(&info);
    initscr();
    timeout(3000);
    keypad(stdscr, FALSE);
    while (key != 'q') {
        display_things(&info);
        key = getch();
        refresh();
        clear();
    }
    endwin();
    return 0;
}

// int main(void)
// {
//     struct sysinfo info;

//     sysinfo(&info);
//     display_first_line();
//     display_second_line();
//     display_line_four(&info);
//     display_line_five();
//     display_files_executing();
//     return 0;
// }
