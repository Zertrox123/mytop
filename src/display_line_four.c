/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** display_fourst_line.c
*/

#include <stdio.h>
#include <sys/sysinfo.h>
#include <ncurses.h>
#include <stdlib.h>

void display_line_four(struct sysinfo *info)
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    double total = info->totalram / (1024.0 * 1024.0);
    double free = info->freeram / (1024.0 * 1024.0);
    double buffer = info->bufferram / (1024.0 * 1024.0);
    double used;
    unsigned long cached = 0;
    char line[256];

    while (fgets(line, sizeof(line), meminfo)) {
        if (sscanf(line, "Cached: %lu", &cached) == 1)
            break;
    }
    fclose(meminfo);
    used = total - free - (buffer + (cached / 1024.0));
    printw("MiB Mem : %7.1f total, %7.1f free, %7.1f used, "
    "%7.1f buff/cache\n", total, free, used, buffer + (cached / 1024.0));
}

// MiB = mibibytes
// 1 MiB = 1024 * 1024 octets
