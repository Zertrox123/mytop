/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** display_second_line.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <ncurses.h>

int handle_option_s(struct dirent *files, int running, int stopped,
    int zombies)
{
    char stat_path[267];
    FILE *stat_file;
    char option;

    if (files->d_name[0] >= '0' && files->d_name[0] <= '9') {
        snprintf(stat_path, 267, "/proc/%s/stat", files->d_name);
        stat_file = fopen(stat_path, "r");
        fscanf(stat_file, "%*d %*s %c", &option);
        fclose(stat_file);
        if (option == 'T')
            stopped++;
    }
    return stopped;
}

int handle_option_r(struct dirent *files, int running, int stopped,
    int zombies)
{
    char stat_path[267];
    FILE *stat_file;
    char option;

    if (files->d_name[0] >= '0' && files->d_name[0] <= '9') {
        snprintf(stat_path, 267, "/proc/%s/stat", files->d_name);
        stat_file = fopen(stat_path, "r");
        fscanf(stat_file, "%*d %*s %c", &option);
        fclose(stat_file);
        if (option == 'R')
            running++;
    }
    return running;
}

int handle_option_t(struct dirent *files, int running, int stopped,
    int zombies)
{
    char stat_path[267];
    FILE *stat_file;
    char option;

    if (files->d_name[0] >= '0' && files->d_name[0] <= '9') {
        snprintf(stat_path, 267, "/proc/%s/stat", files->d_name);
        stat_file = fopen(stat_path, "r");
        fscanf(stat_file, "%*d %*s %c", &option);
        fclose(stat_file);
        if (option == 'Z')
            zombies++;
    }
    return zombies;
}

void display_second_line(void)
{
    DIR *proc_dir = opendir("/proc");
    struct dirent *files;
    int all_tasks = 0;
    int run = 0;
    int stop = 0;
    int zomb = 0;

    files = readdir(proc_dir);
    while (files != NULL) {
        run = handle_option_r(files, run, stop, zomb);
        stop = handle_option_s(files, run, stop, zomb);
        zomb = handle_option_t(files, run, stop, zomb);
        if (files->d_name[0] >= '0' && files->d_name[0] <= '9')
            all_tasks++;
        files = readdir(proc_dir);
    }
    closedir(proc_dir);
    printw("Tasks: %d total, %d running, %d sleeping, %d stopped, "
    "%d zombie\n", all_tasks, run, all_tasks - run - stop - zomb, stop, zomb);
}
