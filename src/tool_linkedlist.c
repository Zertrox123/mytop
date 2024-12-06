/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** display_process.c
*/

#include "../include/mylist.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

linked_list_t *push(linked_list_t *head, char *pid)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    strncpy(list->pid, pid, 10);
    list->next = head;
    return list;
}

int list_free(linked_list_t *head)
{
    linked_list_t *temp;

    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

void print_list(linked_list_t *head)
{
    int max_x;
    int max_y;
    int lines = 0;

    getmaxyx(stdscr, max_y, max_x);
    printw("\n%s\n", "PID");
    lines++;
    while (head->next) {
        if (lines >= max_y - 5)
            break;
        printw("%s\n", head->pid);
        head = head->next;
        lines++;
    }
}

linked_list_t *pid(linked_list_t *head)
{
    struct dirent *files;
    DIR *proc = opendir("/proc");

    files = readdir(proc);
    while (files != NULL) {
        if (isdigit(files->d_name[0]))
            head = push(head, files->d_name);
        files = readdir(proc);
    }
    closedir(proc);
    free(files);
    return head;
}

int display_files_executing(void)
{
    linked_list_t *list = NULL;

    list = pid(list);
    print_list(list);
    list_free(list);
    return 0;
}

// printw("%s %s %s\n", "PID", "USER", "PR");
// printw("%s %s %d\n", head->pid, head->user, head->pr);
// linked_list_t *push(linked_list_t *head, char *pid, char *user, int pr)
// strncpy(list->user, user, 8);
// list->pr = pr;
