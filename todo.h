
#include <stdio.h>
#ifndef TODO_H
#define TODO_H
typedef struct Task {
    char description[100];
    int done;
} Task;
//Todo Manager Methods
void load_tasks();
void save_tasks();
void add_task(const char *desc);
void list_tasks();
void mark_done(int index);

#endif

