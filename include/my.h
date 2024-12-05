/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my.h
*/

#include <stdio.h>
#include <sys/sysinfo.h>
#include <ncurses.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

void display_first_line(void);
void display_second_line(void);
void display_line_four(struct sysinfo *info);
void display_line_five(void);

#endif /* MY_H */
