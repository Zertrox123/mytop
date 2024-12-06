/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** mylist.h
*/

#ifndef MY_LIST_H_
    #define MY_LIST_H_

typedef struct linked_list_s {
    char pid[10];
    char s;
    struct linked_list_s *next;
} linked_list_t;

#endif

// pr = priority
// char user[8];
// int pr;
// int ni;
