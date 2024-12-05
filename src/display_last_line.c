/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** display_last_line.c
*/

#include <stdio.h>
#include <sys/sysinfo.h>
#include <ncurses.h>
#include <stdlib.h>

void display_line_five(void)
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    double total = 0;
    double free = 0;
    double used = 0;
    double avail = 0;
    char line[256];

    while (fgets(line, sizeof(line), meminfo)) {
        if (sscanf(line, "SwapTotal: %lf", &total) == 1)
            total /= 1024.0;
        if (sscanf(line, "SwapFree: %lf", &free) == 1)
            free /= 1024.0;
        if (sscanf(line, "MemAvailable: %lf", &avail) == 1)
            avail /= 1024.0;
    }
    fclose(meminfo);
    used = total - free;
    printw("MiB Swap: %7.1f total, %7.1f free, %7.1f used,"
    " %7.1f avail Mem\n", total, free, used, avail);
}
