/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** display_first_line.c
*/

#include <sys/sysinfo.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>

int user_connect(void)
{
    struct utmp entry;
    int user_count = 0;
    FILE *file = fopen("/var/run/utmp", "rb");

    while (fread(&entry, sizeof(struct utmp), 1, file) == 1) {
        if (entry.ut_type == USER_PROCESS) {
            user_count++;
        }
    }
    fclose(file);
    return user_count;
}

double *load_av(void)
{
    double *load_average = malloc(3);
    FILE *loadavg_file = fopen("/proc/loadavg", "r");

    fscanf(loadavg_file, "%lf %lf %lf", &load_average[0], &load_average[1],
    &load_average[2]);
    fclose(loadavg_file);
    return load_average;
}

int uptime(int boolean)
{
    FILE *uptime_file = fopen("/proc/uptime", "r");
    double uptime_seconds;
    int uptime_minutes;
    int uptime_hours;

    fscanf(uptime_file, "%lf", &uptime_seconds);
    fclose(uptime_file);
    uptime_minutes = (int)(uptime_seconds / 60) % 60;
    uptime_hours = (int)(uptime_seconds / 3600);
    if (boolean == 0)
        return uptime_minutes;
    else
        return uptime_hours;
}

void display_first_line(void)
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    double *load_average = load_av();
    int user_count = user_connect();
    int uptime_hours = uptime(1);
    int uptime_minutes = uptime(0);
    char time_str[9];

    strftime(time_str, 9, "%H:%M:%S", tm_info);
    mvprintw(1, 1, "top - %s up  %d:%02d, %d user%s, load average: %.2f, "
    "%.2f, %.2f\n", time_str, uptime_hours, uptime_minutes, user_count,
    user_count > 1 ? "s" : "", load_average[0], load_average[1],
    load_average[2]);
}
